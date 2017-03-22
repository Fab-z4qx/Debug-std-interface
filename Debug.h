#ifndef Debug_H
#define Debug_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#define std_ofstream std::ofstream
class Debug
{
public:

  struct endll
  {
    //NOTHING
  };

  struct Outf
  {
    Outf()
    {
      std::string env = std::getenv("DEBUG");
      if (env == "true")
        debug = true;
      else
        debug = false;
    }

    int open(const std::string& filePath)
    {
      myFile.open(filePath));
      if (myFile.is_open())
        return true;
      else
        return false;
    }

    int open(const char* filePath)
    {
      myFile.open(filePath, std_ofstream::out | std_ofstream::app);
      if (myFile.is_open())
        return true;
      else
        return false;
    }

    int close()
    {
      myFile.close();

      if (myFile.is_open())
        return false;
      return true;
    }

    template <typename T>
    Outf & operator<< (const T& obj)
    {
      if (debug && myFile.is_open())
        myFile << obj;

      return *this;
    }

    Outf & operator<< (const endll)
    {
      if (debug && myFile.is_open())
        myFile << std::endl;

      return *this;
    }

  private:
    std_ofstream myFile;
    bool debug;

  };

  //SET DEBUG=true TO DISPLAY DEBUG MSG
  struct Out
  {
    Out()
    {
      std::string env = std::getenv("DEBUG");
      if (env == "true")
        debug = true;
      else
        debug = false;
    }

    Out & operator<< (const std::string& token)
    {
      if (debug)
        std::cout << token;

      return *this;
    }

    template <typename T>
    Out & operator<< (const T& obj)
    {
      if (debug)
        std::cout << obj;

      return *this;
    }

    Out & operator<< (const endll /*end*/)
    {
      if (debug)
        std::cout << std::endl;
      return *this;
    }

  private:
    bool debug;
  };

  static Out cout;
  static Outf write;
  static endll endl;
};

/*
Debug::outf << "msg" << Debug::endl;
Debug::write.setFile("toto");
Debug::write << "tutu" << Debug::endl;
*/

#endif /* Debug_H */
