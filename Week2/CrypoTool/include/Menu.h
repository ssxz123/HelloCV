#ifndef MENU_H
#define MENU_H

class Menu{
    private:
        int CryptType;
        void ScreenClear();
        bool StartMenu();
        void ChooseMenu(int Type);
        void encryptText();
        void decryptText();
        void encryptFile();
        void decryptFile();
    public:
        void run();
        
};

#endif