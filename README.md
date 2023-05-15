Programming Assignment #2

Objective:  This assignment will provide further practice with implementing classes.

Task:  For this homework, you will write a class called Temperature, in the files temperature.h and temperature.cpp, for creating and using objects that will store temperatures (like for weather forecasting programs).

This class should be portable, so it should work with any up-to-date C++ compiler. Make sure that it works with g++ on linprog.cs.fsu.edu before you hand it in. You should write some test programs of your own to test the functionality of the class.

Program Details and Requirements:

1) An object of type Temperature should represent a temperature in terms of degrees and scale. Degrees should allow decimal precision (so use type double). The three scales possible are Celsius, Fahrenheit, and Kelvin. You may store the scale however you like inside the object, but for any keyboard input or function parameters, scales will come in as type char, where 'C', 'F', 'K' (as well as the lower case versions) are valid options. Your object must always represent a valid temperature -- remember that 0 Kelvin represents the lowest possible temperature in existence (the complete absence of heat). Your object should also store a format setting, to be used for display of temperatures to the screen.  There will be more than one possible format.  The class features (public interface) should work exactly as specified, regardless of what program might be using Temperature objects.

Note: For purposes of conversions between scales, please remember the following conversion relationships betweeen temperatures:

Celsius = (Fahrenheit - 32) X (5/9)
(or) Fahrenheit = (Celsius X 9/5) + 32
Celsius = Kelvin - 273.15
2) Your Temperature class must provide the following services (i.e. member functions) in its public section.  These functions will make up the interface of the Temperature class.  Make sure you use function prototypes as specified here.  (You may write any other private functions you feel necessary, but the public interface must include all the functionality described here).

the constructor(s): 
The Temperature class should have a constructor that allows the user to specify the values for the degrees and scale, using types double and char, respectively. If any of the values would result in an invalid temperature, the constructor should throw out the erroneous information and initialize the object to represent 0 Celsius, by default. Also, you should allow a Temperature object to be declared without specified parameter values, in which case it should initialize to 0 Celsius (the default).
Examples:  These declarations should be legal, and the comment gives the initialized temperature

 Temperature t1;             // initializes to 0 Celsius 
 Temperature t2(23.5, 'F');  // initializes to 23.5 Fahrenheit 
 Temperature t3(12.6, 'Z');  // invalid scale, initializes to 0 Celsius
 Temperature t4(-300, 'c');  // this is below 0 Kelvin, inits to 0 Celsius
 Temperature t5(15, 'k');    // initializes to 15 Kelvin
void Input() 
This function should prompt the user to enter a temperature, and then allow the user to input a temperature from the keyboard.  User input is expected to be in the format degrees scale, where degrees allows values with decimal precision, and scale is entered as a character. Whenever the user attempts to enter an invalid temperature, the Input function should display an appropriate error message (like "Invalid temperature.  Try again: ") and make the user re-enter the whole temperature.  A few examples of some good and bad inputs:
 Legal:    43.6 k , 53.5 C , 100 F , -273.15 c
 Illegal:  12.3 q , -5 K , -278 C , -500 F       // last 3 are below absolute zero
You may assume that the user entry will always be of the form: 
 D S  where D is a numeric value and S is a character

void Show() 
This function should simply output the temperature to the screen.  There will be more than one possible format for this output, however, and your class will need to store a format setting. The Show function should use the format setting to determine the output.  (There will be a member function that allows the setting to be changed).  When a Temperature object is created, the format setting should start out at the "Default" setting. The possible formats are shown in the following table: 
 
Name	Format	Example	Explanation
Default	D S	50.4316 C	This will look mostly like the input from the Input function. 
Print the degrees and scale as double and char, with default precision on the degrees, and the scale as an uppercase letter
Precision-1	D.d S	50.4 C	Degrees printed to 1 place after the decimal, fixed format, and scale printed as an uppercase letter. This output will need to make sure to put the output stream BACK to its original format settings when you are done, (so that output from a main program isn't now set to 1 decimal place for the caller, for example). See this notes addendum for more details on this kind of thing
Long	D scale	50.4316 Celsius	This display format should show the degrees in default precision, and the scale as the full word "Celsius", "Fahrenheit", or "Kelvin"

 
bool Set(double deg, char s) 
This function should set the temperature to the specified values (the first parameter represents the degrees, the second represents the scale   If the resulting temperature is an invalid temperature, the operation should abort (i.e. the existing stored temperature should not be changed).  This function should return true for success and false for failure (i.e. invalid temperature sent in).
double GetDegrees() 
char GetScale() 
These are "accessor" functions, and they should return the degrees and scale to the caller, respectively.
bool SetFormat(char f) 
This function allows the caller to change the format setting.  The setting should be adjusted inside the object based on the character code passed in.  This means that future uses of the Show function will display in this given format until the format is changed.  The valid setting codes that can be passed in are:
 'D' = Default format 
 'P' = Precision-1 format 
 'L' = Long format 
If an invalid setting code is passed in, do not alter the current format setting.  This function should return true for successful format change, and false for failure (invalid setting given).

bool Convert(char sc) 
This function should convert the current temperature (i.e. the calling object) so that it is now represented in the new scale given in the parameter. You'll need to use the temperature conversion factors for this. If the scale provided is invalid, abort the operation and do not change the current temperature. Otherwise, convert the temperature to the new scale, so that it is equivalent to the previous representation. Return true for success, false for failure (i.e. invalid scale). Examples:
  Temperature t1(68.9, 'F');		// 68.9 Fahrenheit  

  t1.Convert('T');		// invalid scale, no change.  Returns false
  t1.Convert('c');		// t1 is now 20.5 Celsius
  t1.Convert('K');		// t1 is now 293.65 Kelvin
int Compare(const Temperature& d) 
This function should compare two Temperature objects (the calling object and the parameter), and should return: -1 if the calling object is the lower temperature, 0 if the objects represent the same temperature, and 1 if the parameter object is the lower temperature. The function should not change either original object. Example:
  Temperature t1(0, 'C');		// 0 Celsius
  Temperature t2(31.5, 'F');		// 31.5 Fahrenheit

  t1.Compare(t2);		// returns 1  (since t2 comes first)
  t2.Compare(t1);		// returns -1 (calling object is t2, comes first)

3) General Requirements:

all member data of the Temperature class must be private.
The const qualifier must be used on any member functions where it is appropriate
the only libraries that may be used in these class files are <iostream>, <iomanip>, <cctype>, and <string>. Note that you may use the string class to store the words like "Celsius", etc. Although this class can easily be written without using class string.
Do not use langauge or library features that are C++11-only
You only need to do error-checking that is specified in the descriptions above.  If something is not specified (e.g. user entering a letter where a number is expected), you may assume that part of the input will be appropriate. You must always maintain a valid temperature object (in all your functions), but for keyboard input, you may assume that if you ask for a double, you will get a number (not words), for example.
user input and/or screen output should only be done where described (i.e. do not add in extraneous input/output).
no global variables, other than constants
