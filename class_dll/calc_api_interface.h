class calc_api_interface {
    public:
        virtual void initialize() = 0;
        virtual int sum(int a, int b) = 0;
        virtual int multiply(int a, int b) = 0;
};

extern "C" __declspec(dllexport) calc_api_interface* getDllClass();