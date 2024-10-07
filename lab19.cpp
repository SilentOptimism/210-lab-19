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

    void print(){
        float ave = average();
        int count = 1;

        // Prints review
        while(headRatings){

            cout << "\t> Review #" << count << ": " << headRatings->value << ": " << headComment->review << endl;

            headRatings = headRatings->next;
            headComment = headComment->next;
            count++;
        }
        cout << "\t> Average: " << ave << endl;
    }

    float average(){
        float sum = 0;
        int count = 0;

        while(headRatings){
            sum += headRatings->value; 
            headRatings = headRatings->next;
            count++;
        }
        return sum/count;
    }   
    //~Movie();
};

/*
Movie::~Movie(){

}
*/


int main(int argc, char const *argv[]){
    const string txtfile = "comments.txt";

    Movie movieList;

    movieList.build(txtfile);
    movieList.print();

    return 0;
}

