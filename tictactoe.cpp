#include <iostream>
#include <random>

using namespace std;



int main() {

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 600); // define the range

    char input;
    char player1;
    char player2;
    char winner;
    bool flag = true; 
    char arr[3][3];
    char asisstArr[9];
    int turn = 0;

    for(int i = 0; i < 9; ++i){
        asisstArr[i] = distr(gen);
    }
    

    cout << "Choose your player >  Type X or O" << endl;
    while (flag){
        cin >> input;
        if(input == 'X' || input == 'O'){
        cout << "You chose " << input << endl;
        player1 = input;
        if(input == 'X'){
            player2 = 'O';
        } else if(input == 'O'){
            player2 = 'X';
        }
        flag = false;
        } else {
            cout << "Wrong input" << endl;
        }
    }

    flag = true;


    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            
            if(j < 2){
                cout << " ";
                if(arr[i][j] == 'X' || arr[i][j] == 'O'){
                    cout << arr[i][j] << " |";
                } else {
                    cout << 3*i + j << " |";
                }
            } else {
                cout << " ";
                if(arr[i][j] == 'X' || arr[i][j] == 'O'){
                    cout << arr[i][j] << " ";
                } else {
                    cout << 3*i + j << " ";
                }
            }
        }
        cout << endl;
        if(i < 2){
            cout << "-----------" << endl;
        }
        
    }

    cout << endl;

    do
    {
        cout << "Pick a position form 0 - 8" << endl;

        int position;

        try
        {
            cin >> position;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        
        
        if(position >= 0 && position <= 8){

        if(arr[position / 3][position % 3] == 'X' || arr[position / 3][position % 3] == 'O'){
            cout << "This postition is already used" << endl;
            cin >> position;
            
        }
        
        
        if(turn % 2 == 0){
            arr[position / 3][position % 3] = player1;
        } else {
            arr[position / 3][position % 3] = player2;
        }
        if(turn == 8){
            flag = false;
        }
        ++turn;
        
        cout << endl;

         for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            
            if(j < 2){
                cout << " ";
                if(arr[i][j] == 'X' || arr[i][j] == 'O'){
                    cout << arr[i][j] << " |";
                } else {
                    cout << " " << " |";
                }
            } else {
                cout << " ";
                if(arr[i][j] == 'X' || arr[i][j] == 'O'){
                    cout << arr[i][j] << " ";
                } else {
                    cout << " " << " ";
                }
            }
        }
        cout << endl;
        if(i < 2){
            cout << "-----------" << endl;
        }
        
    }
    
    asisstArr[position] = arr[position / 3][position % 3];


    if(asisstArr[0] == asisstArr[1] && asisstArr[0] == asisstArr[2] && asisstArr[1] == asisstArr[2]){
        flag = false;
        winner = asisstArr[0];
    }
    if(asisstArr[3] == asisstArr[4] && asisstArr[3] == asisstArr[5] && asisstArr[4] == asisstArr[5]){
        flag = false;
        winner = asisstArr[3];
    }
    if(asisstArr[6] == asisstArr[7] && asisstArr[6] == asisstArr[8] && asisstArr[7] == asisstArr[8]){
        flag = false;
        winner = asisstArr[6];
    }
    if(asisstArr[0] == asisstArr[3] && asisstArr[0] == asisstArr[6] && asisstArr[3] == asisstArr[6]){
        flag = false;
        winner = asisstArr[0];
    }
    if(asisstArr[1] == asisstArr[4] && asisstArr[1] == asisstArr[7] && asisstArr[4] == asisstArr[7]){
        flag = false;
        winner = asisstArr[1];
    }
    if(asisstArr[2] == asisstArr[5] && asisstArr[2] == asisstArr[8] && asisstArr[5] == asisstArr[8]){
        flag = false;
        winner = asisstArr[2];
    }
    if(asisstArr[0] == asisstArr[4] && asisstArr[0] == asisstArr[8] && asisstArr[4] == asisstArr[8]){
        flag = false;
        winner = asisstArr[0];
    }
    if(asisstArr[2] == asisstArr[4] && asisstArr[2] == asisstArr[6] && asisstArr[4] == asisstArr[6]){
        flag = false;
        winner = asisstArr[2];
    }
        
        } else {
            cout << "Wrong input" << endl;
            flag = true;
        }
    } while (flag);
    
    
    
    cout << "--- Winner winner chiken dinner ---" << endl;
    cout << "      --- Player " << winner << " won ---" << endl;
    
    return 0;

}