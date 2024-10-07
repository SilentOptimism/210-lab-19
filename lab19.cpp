#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

struct Movie
{
    string title;
    float rating;
    string comments;
    Movie *next;

};

// Function headers
Movie* build();
void print(Movie*);
float average(Movie*);

const string fileName = "comments.txt";

int main(int argc, char const *argv[]){

    Movie *head = build();
    print(head);

    return 0;
}

// Builds a movie from use input
Movie* build(){
    char anotherReview = 'y';
    ifstream fin;

    Movie* head = nullptr;
    Movie* current = nullptr;
    fin.open(fileName);

    if(!fin){
        cout << "File opening failure" << endl;
        return nullptr;
    }

    time_t clock;
    srand(time(NULL));

    while (fin)
    {
        Movie *temp = new Movie();
        string comments;
        float rating;

        getline(fin, comments);

        rating = (rand()%5);
        

        // Creates our temporary movie object to be appended
        temp->comments = comments;
        temp->rating = rating;
        temp->next = nullptr;

        // Checks whether to append to the end or the begining
            // Checks if the head is empty
        if(!head){
            head = temp;
            current = head;
        }else{
            current->next = temp;
            current = current->next;
        }
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

