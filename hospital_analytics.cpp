#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    char gender;
    string insurance;
    double total_billing = 0;
};

struct Doctor {
    int id;
    string name;
    string specialization;
    string department;
};

struct Treatment {
    int patient_id;
    int doctor_id;
    string name;
    double cost;
    int duration_days;
};

class HospitalAnalytics {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Treatment> treatments;

    void initialize_sample_data() {
        patients = {
            {1, "John Doe", 45, 'M', "BlueCross"},
            {2, "Jane Smith", 32, 'F', "Medicare"},
            {3, "Alice Wong", 68, 'F', "Aetna"}
        };

        doctors = {
            {101, "Dr. Patel", "Cardiology", "Heart Center"},
            {102, "Dr. Garcia", "Neurology", "Brain Health"},
            {103, "Dr. Chen", "Orthopedics", "Bone Clinic"}
        };
    }

    void calculate_billing() {
        for (auto& patient : patients) {
            patient.total_billing = 0;
            for (const auto& treatment : treatments) {
                if (treatment.patient_id == patient.id) {
                    patient.total_billing += treatment.cost;
                }
            }
        }
    }

public:
    HospitalAnalytics() {
        initialize_sample_data();
    }

    void input_treatment_data() {
        treatments.clear();
        cout << "\nENTER TREATMENT DATA\n";
        cout << "===================\n";

        cout << "Available Patients:\n";
        for (const auto& p : patients) {
            cout << p.id << ". " << p.name << " (" << p.insurance << ")\n";
        }

        cout << "\nAvailable Doctors:\n";
        for (const auto& d : doctors) {
            cout << d.id << ". " << d.name << " (" << d.department << ")\n";
        }

        vector<string> procedures = {
            "Angioplasty", "MRI", "EKG", "Hip Replacement",
            "CT Scan", "Blood Test", "Physical Therapy"
        };

        for (const auto& procedure : procedures) {
            Treatment t;
            t.name = procedure;

            cout << "\nProcedure: " << procedure << "\n";
            
            cout << "Select patient ID: ";
            while (!(cin >> t.patient_id) || t.patient_id < 1 || t.patient_id > 3) {
                cout << "Invalid input! Enter 1, 2, or 3: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Select doctor ID: ";
            while (!(cin >> t.doctor_id)) {
                cout << "Invalid input! Enter 101, 102, or 103: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter cost ($): ";
            while (!(cin >> t.cost) || t.cost <= 0) {
                cout << "Invalid input! Enter positive value: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter duration (days): ";
            while (!(cin >> t.duration_days) || t.duration_days <= 0) {
                cout << "Invalid input! Enter positive value: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            treatments.push_back(t);
        }

        calculate_billing();
    }

    void insurance_report() {
        map<string, pair<int, double>> coverage;
        for (const auto& patient : patients) {
            coverage[patient.insurance].first++;
            coverage[patient.insurance].second += patient.total_billing;
        }

        cout << "\nINSURANCE COVERAGE REPORT\n";
        cout << "=======================\n";
        for (const auto& [provider, data] : coverage) {
            cout << left << setw(12) << provider << ": " << data.first << " patients ("
                 << fixed << setprecision(1) << (data.first * 100.0 / patients.size())
                 << "%), Total billing: $" << data.second << "\n";
        }
    }

    void treatment_stats() {
        if (treatments.empty()) {
            cout << "\nNo treatment data available!\n";
            return;
        }

        vector<double> costs;
        for (const auto& t : treatments) costs.push_back(t.cost);

        double mean = accumulate(costs.begin(), costs.end(), 0.0) / costs.size();
        sort(costs.begin(), costs.end());
        double median = costs.size() % 2 ? costs[costs.size()/2] 
                                       : (costs[costs.size()/2-1] + costs[costs.size()/2])/2;
        double sq_sum = inner_product(costs.begin(), costs.end(), costs.begin(), 0.0);
        double stdev = sqrt(sq_sum/costs.size() - mean*mean);
        auto max_t = *max_element(treatments.begin(), treatments.end(),
                                [](const Treatment& a, const Treatment& b) {
                                    return a.cost < b.cost;
                                });

        cout << "\nTREATMENT STATISTICS\n";
        cout << "===================\n";
        cout << left << setw(20) << "Mean cost:" << "$" << mean << "\n";
        cout << setw(20) << "Median cost:" << "$" << median << "\n";
        cout << setw(20) << "Standard deviation:" << "$" << stdev << "\n";
        cout << setw(20) << "Most expensive:" << "$" << max_t.cost 
             << " (" << max_t.name << " for patient " << max_t.patient_id << ")\n";
    }

    void department_report() {
        map<string, vector<double>> dept_data;
        for (const auto& t : treatments) {
            for (const auto& d : doctors) {
                if (d.id == t.doctor_id) {
                    dept_data[d.department].push_back(t.cost * 0.3);
                    break;
                }
            }
        }

        cout << "\nDEPARTMENT PERFORMANCE\n";
        cout << "=====================\n";
        for (const auto& [dept, revenues] : dept_data) {
            double total = accumulate(revenues.begin(), revenues.end(), 0.0);
            cout << dept << ":\n";
            cout << "  " << left << setw(18) << "Total revenue:" << "$" << total << "\n";
            cout << "  " << setw(18) << "Cases handled:" << revenues.size() << "\n";
            cout << "  " << setw(18) << "Avg revenue/case:" << "$" << total/revenues.size() << "\n";
        }
    }

    void full_report() {
        insurance_report();
        treatment_stats();
        department_report();
    }
};

void show_menu() {
    cout << "\nHOSPITAL ANALYTICS MENU\n";
    cout << "======================\n";
    cout << "1. Insurance Coverage Report\n";
    cout << "2. Treatment Cost Analysis\n";
    cout << "3. Department Performance\n";
    cout << "4. Full Analysis Report\n";
    cout << "5. Re-enter Treatment Data\n";
    cout << "6. Exit\n";
    cout << "Select option: ";
}

int main() {
    HospitalAnalytics analytics;
    analytics.input_treatment_data();

    int choice;
    do {
        show_menu();
        while (!(cin >> choice) || choice < 1 || choice > 6) {
            cout << "Invalid input! Enter 1-6: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch(choice) {
            case 1: analytics.insurance_report(); break;
            case 2: analytics.treatment_stats(); break;
            case 3: analytics.department_report(); break;
            case 4: analytics.full_report(); break;
            case 5: analytics.input_treatment_data(); break;
            case 6: cout << "Exiting program...\n"; break;
        }
    } while (choice != 6);

    return 0;
}
