#include "CommonHeader.h"

namespace dir
{
    class CDir
    {
    public:
        CDir(const char * const DirPath);
        CDir(std::string & DirPath);
        virtual ~CDir();
    
    private:
        void CreateDir();
        void DeleteDIr();
        bool changeMode(CDir dir);

    public:
        static void jh_ChangeMode(CDir _dir)
        {

        }

        static bool jh_isExist(std::string & _DirPath)
        {
            return true;
        }    
    };
} /* namespace dir */