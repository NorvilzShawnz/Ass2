#include <iostream>
#include <cctype>
#include "temperature.h"
int main(){
    // Temperature t1;
    // Temperature t2(127.693902, 'C');
    // // t1.Input();
    // t2.Show();
    // t2.SetFormat('p');
    // t2.Show();
    // t2.SetFormat('l');
    // t2.Show();
    // t1.Set(389.67, 'C');
    // t1.Set(389.67, 'K');
    // t2.SetFormat('p');
    // t2.Show();
    // t2.SetFormat('d');
    // t2.Show();
    // t2.Convert('K');
    // t2.Show();
    // t2.Convert('F');
    // t2.Show();
    // t1.Set(37, 'K');
    // t2.Set(120, 'K');
    // t1.Compare(t2);
    // t1.Show();
    // t2.Show();
   Temperature t1;		// should default to 0 Celsius
   Temperature t2(34.5, 'F');  // should init to 34.5 Fahrenheit 

   // display dates to the screen
   std::cout << "\nTemperature t1 is: ";
   t1.Show();			
   std::cout << "\nTemperature t2 is: ";
   t2.Show();

   t1.Input();			// Allow user to enter a temperature for t1
   std::cout << "\nTemperature t1 is: ";
   t1.Show();			
   
   t1.SetFormat('L');		// change format of t1 to "Long" format
   t1.SetFormat('D');
   t1.SetFormat('P');
   std::cout << "\nTemperature t1 is: ";
   t1.Show();			

   // and so on.  Add your own tests to fully test the class' 
   //   functionality./

}
Temperature::Temperature(){
        degree = 0;
        scale = 'C';
    }
Temperature::Temperature(double x, char y){
        if (((y == 'C') || (y == 'c')) && (x < (-273.15))){
            std::cout<< "Invalid entry, Temperature set to 0 Degrees Celsius"<<std::endl;
            degree = 0;
            scale = 'C';
        }
        else if (((y == 'K') || (y== 'k')) && (x < 0)){
            std::cout<< "Invalid Entry, Temperature set to 0 Degrees Celsius"<<std::endl;
            degree = 0;
            scale = 'C';
        }
        else if (((y == 'F') || (y== 'f')) && (x < -459.67) ){
            std::cout<< "Invalid Entry, Temperature set to 0 Degrees Celsius"<<std::endl;
            degree = 0;
            scale = 'C';
        }
        else{
            degree = x;
            scale =y;
            std::cout<< "Degree and Scale initialized to " << degree << " degrees " << scale <<std::endl;
        }
    }
void Temperature::Input(){
        double y;
        char z;
        std::cout<<"Enter a temperature"<<std::endl;
        std::cin>>y;
        std::cin>>z;
       if (((z == 'C') || (z == 'c')) && (y < (-273.15))){
            std::cout<< "Invalid Temperature, please try again"<<std::endl;
            Input();
        }
        else if (((z == 'K') || (z== 'k')) && (y < 0)){
            std::cout<< "Invalid Temperature, please try again"<<std::endl;
            Input();
        }
        else if (((z == 'F') || (z== 'f')) && (y < -459.67) ){
            std::cout<< "Invalid Temperature, please try again"<<std::endl;
            Input();
        }
        else{
            degree = y;
            scale = z;
            std::cout<< "Degree and Scale changed to " << degree << " degrees " << (char) toupper(scale) <<std::endl;
        }
}
void Temperature::Show(){
    if ((format == 'd') || (format == 'D')){
        std::cout<< degree << " " << scale << std::endl;
    }
    else if ((format == 'p') || (format == 'P')){
        int oldprecision = std::cout.precision();
        std::cout << std::fixed;
        std::cout.precision(1);
        std::cout<< degree << " "<< scale << std::endl;
        std::cout.precision(oldprecision);
    }
    else if ((format == 'l') || (format == 'L')){
        if (scale == 'C'){
            std::cout << degree << " " << "Celsius" << std::endl;
        }
        else if (scale == 'F'){
            std::cout << degree << " " << "Fahrenheit" << std::endl;
        }
        else if (scale == 'K'){
            std::cout<< degree << " " << "Kelvin" << std::endl;
        }
    }
    else{
        std::cout<< "For some reason the format is not set, or it is not set as one of the available formats, returning it to Default. " << std::endl;
        format = 'd';
    } 
}
bool Temperature::Set(double deg, char s){
    // Not Done, Needs Input Validation for Degrees and Scale
    //Done
    double newDegree = deg;
    char newScale = s;
    if ( (newScale == 'K') && (newDegree < 0)){
        std::cout<<"Invalid Temperature"<<std::endl;
        return false;
    }
    else if ( (newScale == 'C') && (newDegree < -273.15)){
        std::cout<<"Invalid Temperature"<<std::endl;
        return false;
    }
    else if ((newScale == ' F') && (newDegree < -459.67)){
        std::cout<<"Invalid Temperature"<<std::endl;
        return false;
    }
    else{
        degree = newDegree;
        scale = newScale;
        Show();
        return true;
    }
}
double Temperature::GetDegrees(){
    return degree;
}
char Temperature::GetScale(){
    return scale;
}
bool Temperature::SetFormat(char f){
    //Needs Input Validation for valid Formats

    //Done
    if ((f == 'p') || (f =='P')){
        format = f;
        return true;
    }
    else if ((f == 'l') || (f =='L')){
        format = f;
        return true;
    }
    else if((f == 'd') || (f =='D')){
        format = f;
        return true;
    }
    else{
        std::cout<< "Invalid Format" << std::endl;
        return false;
    }
}
bool Temperature::Convert(char sc){
    // Needs conversion and validation of conversions
    char currentScale = scale;
    char newScale;
    double currentTemp = degree;
    double newTemp;
    //If the scale that i'm converting to, is Celsius
    // and if the current scale is not Celsius
    // then the newScale is celsius
    //Now if the currentScale is Kelvin, and the newScale is Celsius then I convert Kelvin to Celsius
    // Or If the currentScale is Fahrenheit and the newScale is Celsius then I convert Fahrenheit to Celsius
    //
    if ((sc == 'c') || (sc =='C')){
        if (currentScale != sc){
            newScale = sc;
            if ( ((currentScale == 'K') || (currentScale == 'k')) && ((newScale == 'c') || (newScale == 'C'))){
                newTemp -= 273.15;
                degree = newTemp;
                scale = newScale;
                return true;
            }
            else if(((currentScale == 'F') || (currentScale == 'f')) && (((newScale == 'c') || (newScale == 'C')))){
                newTemp = ((degree-32)*5)/9;
                degree = newTemp;
                scale = newScale;
                return true;
            }
            else{
                std::cout<< "This is the current Scale, therefore the Temperature has not changed" << std::endl;
                return false;
            }
        }
    }
    // If the scale that i'm converting to, is Fahrenheit
    // and if the current scale is not Fahrenheit
    // change the newScale to Fahrenheit
    // if current scale is K and the newScale is F, convert Kelvin to Fahrenheit
    // or if the current scale is C and the newScale is F, convert Celsius to Fahrenheit 
    else if ((sc == 'f') || (sc =='F')){
        if(currentScale != sc){
        newScale = sc;
            if ( ((currentScale == 'K') || (currentScale == 'k')) && ((newScale == 'f') || (newScale == 'F'))){
                newTemp = (((degree - 273.15)*9)/5) + 32;
                degree = newTemp;
                scale = newScale;
                return true;
            }
            else if(((currentScale == 'C') || (currentScale == 'c')) && (((newScale == 'f') || (newScale == 'F')))){
                newTemp = (degree*9)/5 + 32;
                degree = newTemp;
                scale = newScale;
                return true;
            }
            else{
                std::cout<< "This is the current Scale, therefore the Temperature has not changed" << std::endl;
                return false;
    }
        }
    }
    else if((sc == 'k') || (sc =='K')){
        newScale = sc;
            if ( ((currentScale == 'C') || (currentScale == 'c')) && ((newScale == 'k') || (newScale == 'K'))){
                newTemp = degree + 273.15;
                degree = newTemp;
                scale = newScale;
                return true;
            }
            else if(((currentScale == 'F') || (currentScale == 'f')) && (((newScale == 'k') || (newScale == 'K')))){
                newTemp = (((degree - 32)*5)/9) + 273.15;
                degree = newTemp;
                scale = newScale;
            }
            else{
                std::cout<< "This is the current Scale, therefore the Temperature has not changed" << std::endl;
                return false;
    }
    }
    else{
    std::cout<<"Invalid Scale, No Change "<<std::endl;
    return false;
}
}

int Temperature::Compare(const Temperature& d){
    if ((this->degree == d.degree) && (this->scale == d.scale)){
        std::cout<<"They are equal. "<<std::endl;
        return 0;
    }
    if(this->scale == d.scale){
        if(this->degree < d.degree){
            std::cout<<"Call object is less than paramter object" <<std::endl;
            return -1;
        }
        else if (this->degree > d.degree){
            std::cout<<"Call object is Greater than paramter object" <<std::endl;
            return 1;
        }
    }
    else if (this->scale != d.scale){
        char callScale = this->scale;
        if ((d.scale == 'C') || (d.scale == 'c')){
            std::cout<<"Parameter Object's scale is C" << std::endl;
            this->Convert(d.scale);
            if (this->degree < d.degree){
                this->Convert(callScale);
                std::cout<< "Call Scale is: "<< callScale << std::endl;
                return -1;
            }
            else if (this->degree > d.degree){
                this->Convert(callScale);
                std::cout<< "Call Scale is: "<< callScale << std::endl;
                return 1;
            }
        }
        else if ((d.scale == 'K') || (d.scale == 'k')){
            std::cout<<"Parameter Object's scale is K" << std::endl;
            this->Convert(d.scale);
            if (this->degree < d.degree){
                this->Convert(callScale);
                std::cout<< "Call Scale is: "<< callScale << std::endl;
                return -1;
            }
            else if (this->degree > d.degree){
                this->Convert(callScale);
                std::cout<< "Call Scale is: "<< callScale << std::endl;
                return 1;
            }
        }
        else if ((d.scale == 'F') || (d.scale == 'f')){
            std::cout<<"Parameter Object's scale is F" << std::endl;
            this->Convert(d.scale);
            if (this->degree < d.degree){
                this->Convert(callScale);
                std::cout<< "Call Scale is: "<< callScale << std::endl;
                return -1;
            }
            else if (this->degree > d.degree){
                this->Convert(callScale);
                std::cout<< "Call Scale is: "<< callScale << std::endl;
                return 1;
            }
        }
    }
    // else if (){

    // }
    // else if (){
        
    // }

}   