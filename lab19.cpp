#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Movie
{
    float rating;
    string comments;
    Movie *next;

};

// Function headers
Movie* build();
void print(Movie*);
float average(Movie*);

int main(int argc, char const *argv[]){

    Movie *head = build();
    print(head);

    return 0;
}

// Builds a movie from use input
Movie* build(){
    char anotherReview = 'y';
    int headTail = 0;

    Movie* head = nullptr;
    Movie* current = nullptr;

    cout << "Which linked list method should we use?" << endl;
    cout << "\t[1] New nodes are added at the head of the linked list" << endl;
    cout << "\t[2] New nodes are added at the tail of the linked list" << endl;
    cin >> headTail;

    // User validation
    while(headTail < 1 || headTail > 2){
        cout << "Invalid input: You have to input 1 or 2";
        cout << "Which linked list method should we use?" << endl;
        cout << "\t[1] New nodes are added at the head of the linked list" << endl;
        cout << "\t[2] New nodes are added at the tail of the linked list" << endl;
        cin >> headTail;
    }

    // Check's if the user want's to continue
    while(tolower(anotherReview) != 'n'){
        int rating = 0;
        string comments;

        // Gets the review rating and checks if its in range
        cout << "Enter review rating 0-5: ";
        cin >> rating;

        // User validation
        while (rating > 5 || rating < 0){
            cout << "Review must be between 0-5";
            cout << "Enter review rating 0-5: ";
            cin >> rating;
        }
        
        // Stops getline from grabing the \n
        cin.ignore(1000, '\n');

        // Gets users comments
        cout << "Enter review coments: ";
        getline(cin, comments);

        Movie *temp = new Movie();

        // Creates our temporary movie object to be appended
        temp->comments = comments;
        temp->rating = rating;
        temp->next = nullptr;

        // Checks whether to append to the end or the begining
        if(headTail == 1){
            // Checks if the head is empty
            if(!head){
                head = temp;
                current = head;
            }else{
                current->next = temp;
                current = current->next;
            }
        }else{
            temp->next = head;
            head = temp;
        }

        cout << "Enter another input? Y/N: ";
        cin >> anotherReview;
    }
    return head;
}



void print(Movie* head){
    float ave = average(head);
    int count = 1;

    // Prints review
    while(head){
        cout << "\t> Review #" << count << ": " << head->rating  << ": " << head->comments << endl;
        head = head->next;
        count++;
    }
    cout << "\t> Average: " << ave << endl;
}

float average(Movie* head){
    float sum = 0;
    int count = 0;

    while(head){
        sum += head->rating;
        head = head->next;
        count++;
    }

    return sum/count;
}

//Returns Movie at given index

