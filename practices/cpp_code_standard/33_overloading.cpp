//https://articles.emptycrate.com/2009/02/03/overloading__and__operators_in_c.html 

#include <iostream>
 
bool getbool(bool b)
{
  std::cout << " getbool called " << std::endl;
  return b;
}
struct Boolean
{
  private:
    bool value;

  public:
    Boolean(bool t_value)
      : value(t_value)
    {
    }

    operator bool() const
    {
      return value;
    }
};

Boolean getBoolean(bool b)
{
  std::cout << " getBoolean called " << std::endl;
  return Boolean(b);
}

int main()
{
  std::cout << " Testing getbool || expecting 1 output: " << std::endl;
  if (getbool(true) || getbool(false))
  {
  }

  std::cout << " Testing getbool || expecting 2 outputs: " << std::endl;
  if (getbool(false) || getbool(true))
  {
  }

  std::cout << " Testing getbool && expecting 1 outputs: " << std::endl;
  if (getbool(false) && getbool(true))
  {
  }

  std::cout << " Testing getBoolean || expecting 1 outputs:" << std::endl;
  if (getBoolean(true) || getBoolean(false))
  {
  }

  std::cout << " Testing getBoolean && expecting 1 outputs:" << std::endl;
  if (getBoolean(false) && getBoolean(true))
  {
  }
}
