#include <iostream>
#include <cmath>

using namespace std ;



void print_piramida(int SizeArray, int Array[]){
     cout << "Исходнный массив: ";
        for(int i = 0 ; i <SizeArray; i++ )
        
            cout << Array[i]<< " ";
        
        cout << endl;
    for (int index = 0 ; index < SizeArray ; index++ )
    {   
        int level  = static_cast<int>(log2(index +1));
        string type ;
        int parent_index = (index -1) /2; 
        if (index == 0)
        {
          type = "root";    
        } 
        else if (index == 2 * parent_index + 1 )
        {
            type = "left";   
        }
        else
        {
            type = "right";
        }

        if (type == "root")
        {
            cout <<level << " "<< type <<" "<< Array[index]<< endl;
        }
        else 
        {
         int parent_value = Array[parent_index];
         cout << level << " "<< type << "("<<parent_value<<")"<< Array[index]<< endl;
        }

        
    }
}

int main ()
{
    int SizeArray = 10;
    int array[SizeArray] = {55,3,10,100,234,47,33,8,26,22};
    print_piramida(SizeArray,array);
}