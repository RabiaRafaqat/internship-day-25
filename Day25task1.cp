#include <iostream>
#include <string>
using namespace std;

void addCandidates(string candidates[], int& numCandidates);
void castVote(const string candidates[], int numCandidates, int votes[]);
void displayResults(const string candidates[], const int votes[], int numCandidates);

int main() {
    const int MAX_CANDIDATES = 10;
    string candidates[MAX_CANDIDATES];
    int votes[MAX_CANDIDATES] = {0};
    int numCandidates = 0;
    int choice;

    while (true) {
        cout << "\nVoting System Menu:" << endl;
        cout << "1. Add candidates" << endl;
        cout << "2. Cast a vote" << endl;
        cout << "3. Display results" << endl;
        cout << "4. Exit" << endl;
        cout << "Please choose an option (1-4): ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1:
                addCandidates(candidates, numCandidates);
                break;
            case 2:
                castVote(candidates, numCandidates, votes);
                break;
            case 3:
                displayResults(candidates, votes, numCandidates);
                break;
            case 4:
                cout << "Thank you for using the voting system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid option. Please enter a number between 1 and 4." << endl;
                break;
        }
    }

    return 0;
}

void addCandidates(string candidates[], int& numCandidates) {
    cout << "How many candidates do you want to add (up to 10)? ";
    cin >> numCandidates;
    cin.ignore();  

    if (numCandidates > 10) {
        numCandidates = 10;
        cout << "You can only add up to 10 candidates. Adjusting to 10." << endl;
    }

    for (int i = 0; i < numCandidates; ++i) {
        cout << "Enter the name of candidate " << (i + 1) << ": ";
        getline(cin, candidates[i]);
    }

    cout << "Candidates added successfully!" << endl;
}

void castVote(const string candidates[], int numCandidates, int votes[]) {
    if (numCandidates == 0) {
        cout << "No candidates available. Please add candidates before voting." << endl;
        return;
    }

    cout << "Enter the name of the candidate you want to vote for: ";
    string vote;
    getline(cin, vote);

    bool voteCasted = false;
    for (int i = 0; i < numCandidates; ++i) {
        if (candidates[i] == vote) {
            votes[i]++;
            voteCasted = true;
            cout << "Your vote for " << candidates[i] << " has been recorded." << endl;
            break;
        }
    }

    if (!voteCasted) {
        cout << "Candidate not found. Please check the name and try again." << endl;
    }
}

void displayResults(const string candidates[], const int votes[], int numCandidates) {
    if (numCandidates == 0) {
        cout << "No results to display. Please add candidates and cast votes first." << endl;
        return;
    }

    cout << "Election Results:" << endl;
    for (int i = 0; i < numCandidates; ++i) {
        cout << candidates[i] << " received " << votes[i] << " vote(s)." << endl;
    }
}