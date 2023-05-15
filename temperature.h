class Temperature {
    private:
    double degree;
    char scale;
    char format = 'd';
    
    public:
    Temperature();
    Temperature(double x, char y);
    void Input();
    void Show();
    bool Set(double deg, char s);
    double GetDegrees();
    char GetScale();
    bool SetFormat(char f);
    bool Convert(char sc);
    int Compare(const Temperature& d);
};