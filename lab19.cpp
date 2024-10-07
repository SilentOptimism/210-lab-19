#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

struct Comments
{
    string review;
    Comments *next;
};

struct Ratings 
{
    float value;
    Ratings *next;
};

class Movie
{
private:
    string title;
    Comments *headComment;
    Ratings *headRatings;

public:
    // Constructs the movie ratings/comments based on given text file
    // Inputs: string textFileName
    // Outputs: none
    void build(string textFileName){
        char anotherReview = 'y';
        ifstream fin;

        fin.open(textFileName);

        if(!fin){
            cout << "File opening failure" << endl;
        }

        time_t clock;
        srand(time(NULL));

        while (fin)
        {
            Comments *tempComments = new Comments();
            Ratings *tempRatings = new Ratings();

            string comment;
            float rating;

            getline(fin, comment);

            if(fin){
                rating = (rand()%6);

                // Creates temp Review/Comment structs
                tempComments->review = comment;
                tempComments->next = nullptr;
                tempRatings->value = rating;
                tempRatings->next = nullptr;

                // Checks whether to append to the end or the begining
                // Checks if the head is empty
                tempComments->next = headComment;
                tempRatings->next = headRatings;
                headComment = tempComments;
                headRatings = tempRatings;
            }
        }
    }

    // Prints out the review information to the console
    // Inputs: none
    // Returns: none
    void print(){
        float ave = average();
        int count = 1;

        Comments* currentComments = headComment;
        Ratings* currentRatings = headRatings;

        // Prints review
        while(currentRatings->next){

            cout << "\t> Review #" << count << ": " << currentRatings->value << ": " << currentComments->review << endl;

            currentRatings = currentRatings->next;
            currentComments = currentComments->next;
            count++;
        }
        cout << "\t> Average: " << ave << endl;
    }

    // Calculates the average
    // Inputs: none
    // Returns: float
    float average(){
        Ratings* currentRatings = headRatings;

        float sum = 0;
        int count = 0;

        // gets the average/count
        while(currentRatings->next){
            sum += currentRatings->value; 
            currentRatings = currentRatings->next;
            count++;
        }
        return sum/count;
    }   
};

int main(int argc, char const *argv[]){
    const string txtfile = "comments.txt";

    Movie movieList;

    movieList.build(txtfile);
    movieList.print();

    return 0;
}

