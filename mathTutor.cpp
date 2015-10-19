//Name:Nancy Gomez
//Name:Regie Daquioag
//Name:Thalia Villalobos
//16 Oct. 2015
//

#include<iostream>
#include <cstdlib>
#include <ctime>
#include<string>
#include<cassert>
using namespace std;

char menu();
//****************************************************************************************
//Precondition: Called in main() and will print out the options: (+,-,*,/,Q). 
//Postcondition: It will return the char choice the user picked  and it will be used in
//a switch to actually pick which section they wanted.
//Summary: It asks the user what section they would like to work in.
//*****************************************************************************************

int randGen();
//****************************************************************************************
//Precondition: Takes in no parameters, is called in every single math function twice
//Postcondition: A random number is generated between 1 through 12.d
//Returns that number to wherever it was called.
//Summary: Creates a random number between 1 through 12
//*****************************************************************************************

int addition();
//*******************************************************************************************
//Precondition: It takes in no parameter and it will be called upon if ‘+’ was chosen
//Postcondition: Two random numbers are generated for every question. Count will
//keep track of correct answers. Either a compliment/encouragement will be printed.
//Summary: The function will ask addition questions and keep track of correct answers.
//********************************************************************************************

int subtraction();
//*******************************************************************************************
//Precondition: It takes in no parameter and it will be called upon if ‘-’ was chosen
//Postcondition: Two random numbers are generated for every question. Count will
//keep track of correct answers. Either a compliment/encouragement will be printed.
//Summary: The function will ask subtraction questions and keep track of correct answers.
//********************************************************************************************

int multiplication();
//*******************************************************************************************
//Precondition: It takes in no parameter and it will be called upon if ‘*’ was chosen
//Postcondition: Two random numbers are generated for every question. Count will
//keep track of correct answers. Either a compliment/encouragement will be printed.
//Summary: The function will ask multiplication questions & keep track of correct answers.
//********************************************************************************************

int division();
//*******************************************************************************************
//Precondition: It takes in no parameter and it will be called upon if ‘+’ was chosen
//Postcondition: Two random numbers are generated for every question. The numbers
// must be divisible and the second can not be zero. Count will keep track of correct
//answers. Either a compliment/encouragement will be printed.
//Summary: The function will ask division questions and keep track of correct answers.
//********************************************************************************************

string compliment();
//***************************************************
//Precondition: 
//Postcondition: 
//Summary: 
//***************************************************

string encouragement();
//***************************************************
//Precondition: 
//Postcondition: 
//Summary: 
//***************************************************


int main()
{   
	srand(time(0));
	char userChoice;
	int overAllTotal=0;
	int eachCount = 0;
	
	do
	{
	    userChoice = menu();
	    
	    switch (userChoice){
	        case '+': eachCount = addition();
	                  cout << "Total correct answered for this session: " << eachCount << endl;
	                  overAllTotal += eachCount;
	                  cout << "Overall score so far: " << overAllTotal << endl;
	                  break;
	        case '-': eachCount = subtraction();
	                  cout << "Total correct answered for this session: " << eachCount << endl;
	                  overAllTotal += eachCount;
	                  cout << "Overall score so far: " << overAllTotal << endl;
	                  break;
	        case '*': eachCount = multiplication();
	                  cout << "Total correct answered for this session: " << eachCount << endl;
	                  overAllTotal += eachCount;
	                  cout << "Overall score so far: " << overAllTotal << endl;
	                  break;
	        case '/': eachCount = division();
	                  cout << "Total correct answered for this session: " << eachCount << endl;
	                  overAllTotal += eachCount;
	                  cout << "Overall score so far: " << overAllTotal << endl;
	                  break;
	        case 'q': 
	        case 'Q': cout << "Your overall score: " << overAllTotal << endl;
	                  userChoice = 'Q';
	                  break;
	        default:
	              cout << "Error unkown symbol, please try again. Reenter your input: " << endl;
	              cin >> userChoice;
	              break;
	     }
	}while (userChoice != 'Q');

    return 0;
}
 
 
char menu()
{
    char userChoice;
    
    cout << "\nWelcome Math Tutor 2.0 " << endl;
    cout << "Today's subjects: Addition, Subtraction" << endl;
    cout << "Multiplication and Division" << endl;
    cout << "For Addition please enter in '+'" << endl;
    cout << "For Subtraction please enter in '-'" << endl;
    cout << "For Multiplication please enter in '*'" << endl; 
    cout << "For Division please enter in '/'" << endl; 
    cout << "If you want to stop please enter in 'Q'" << endl; 
    cin >> userChoice;
    
    return userChoice;
}

int randGen()
{
	int randNum = rand() % 12 + 1;
	return randNum;
}
 
int addition()
{
    int answer, userAnswer;
    int count = 0;
    
    for (int ix = 0; ix < 5; ix++)
    {
        int num1 = randGen();
        int num2 = randGen();
        
        cout << "What is " << num1 << " + " << num2 << "? ";
        cin >> userAnswer;
        answer = (num1 + num2);
        
        if (userAnswer == answer)
        {
            cout << compliment() << endl;
            count++;            
        }
        else
        {
            cout << encouragement() << " The correct answer is: " << answer << "\n"<< endl;
        }        
    }
    return count; 
}
 
int subtraction()
{
    int answer, userAnswer;
    int count = 0;
    
    for (int ix = 0; ix < 5; ix++)
    {
        int num1 = randGen();
        int num2 = randGen();
        
        if (num1 >= num2)
        {              
            cout << "What is " << num1 << " - " << num2 << "? ";
            cin >> userAnswer;
            answer = (num1 - num2);
            
            if (userAnswer == answer)
            {
                cout << compliment() << endl;
                count++;            
            }
            else
            {
                cout << encouragement() << " The correct answer is: " << answer << "\n"<< endl;
            }
        
        else if (num2 > num1)
        {             
            cout << "What is " << num2 << " - " << num1 << "? ";
            cin >> userAnswer;
            answer = (num2 - num1);
            
            if (userAnswer == answer)
            {
                cout << compliment() << endl;
                count++;            
            }
            else
            {
                cout << encouragement() << " The correct answer is: " << answer << "\n"<< endl;
            }
        }   
    }
    return count; 
}

int multiplication()
{
	int num1, num2, userAnswer, answer;
	int count = 0;
	for (int i = 0; i < 5; i++){
		num1 = randGen(), num2 = randGen();
		cout << "What is " << num1 << " x " << num2 << "? ";
		cin >> userAnswer;
	
		answer = num1 * num2;
		if (userAnswer == answer){
			cout << compliment() << endl;
			count++;
		}
		else{
			cout << encouragement() << " The correct answer is: " << answer << "\n"<< endl;
		}
	}
	return count;
}

int division()
{
	int num1, num2, userAnswer, answer;
	int count = 0;
	for (int i = 0; i < 5; i++){
		num1 = randGen(), num2 = randGen();
		while ( (num1 % num2 != 0) || (num2 == 0) ){
		num1 = randGen();
		num2 = randGen();
		}
		cout << "What is " << num1 << " / " << num2 << "? ";
		cin >> userAnswer;
	
		answer = num1 / num2;
		if (userAnswer == answer){
			cout << compliment() << endl;
			count++;
		}
		else{
			cout << encouragement() << " The correct answer is: " << answer << "\n"<< endl;
		}
	}
	return count;
}

string compliment()
{   
    string sentence;
    int randNum = rand() % 4 + 1;
    
    switch (randNum){
        case 1: sentence = "Correct! Way to go （＾ｖ＾）\n";
                return sentence;
                break;
        case 2: sentence = "Awesome ^o^, you got the correct answer\n";
                return sentence;
                break;
        case 3: sentence = "Correct! You are a superstar ✯◡✯!\n";
                return sentence;
                break;
        case 4: sentence = "Correct! Your doing great, keep going （‐＾▽＾‐）\n";
                return sentence;
                break;
        default:
                break;
    }
}

string encouragement()
{
    string sentence;
    int randNum = rand() % 4 + 1;
    
    switch (randNum){
        case 1: sentence = "Sorry ͼ(ݓ_ݓ)ͽ , that is wrong.";
                return sentence;
                break;
        case 2: sentence = "Incorrect (~_^), keep trying.";
                return sentence;
                break;
        case 3: sentence = "Dont give up (ô‿ô), you can do this.";
                return sentence;
                break;
        case 4: sentence = "Keep going, don't stop (҂⌣̀_⌣́)ᕤ. ";
                return sentence;
                break;
        default:
                break;
    }

}

