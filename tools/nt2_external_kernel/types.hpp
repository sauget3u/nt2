#ifndef TYPES_HPP_INCLUDED
#define TYPES_HPP_INCLUDED

#include <boost/range/iterator_range.hpp>
#include <string>
#include <vector>
#include <map>
#include <ostream>

struct type_infos
{
  type_infos() {}
  type_infos( std::string const& value_type_, bool container_ = false )
           : value_type(value_type_), container(container_)
           {
           }

  std::string value_type;
  bool container;
  std::map<std::string, std::string> settings;
};

struct expression
{
  expression() {}
  expression( std::string const& operation_, type_infos const& type_, std::vector<expression> const& children_ )
               : operation(operation_), type(type_), children(children_)
               {
               }

  std::string operation;
  type_infos type;
  std::vector<expression> children;
};

struct tagged_expression
{
  tagged_expression() {}
  tagged_expression( boost::iterator_range<const char*> const& raw_, expression const& expr_ )
                   : raw(raw_.begin(), raw_.end()), expr(expr_)
                   {
                   }

  std::string raw;
  expression expr;
};

struct kernel_symbol
{
  kernel_symbol() {}
  kernel_symbol( std::string const& kernel_, std::string const& target_, std::vector<tagged_expression> const& arguments_ )
               : kernel(kernel_), target(target_), arguments(arguments_)
               {
               }

  std::string kernel;
  std::string target;
  std::vector<tagged_expression> arguments;
};

struct pretty_printer
{
  pretty_printer(std::ostream& os_, std::size_t indentation_) : os(os_), indentation(indentation_)
  {
  }

  void indent()
  {
    for(std::size_t i=0; i!=indentation; ++i)
      os << "  ";
  }

  template<class T>
  void operator()(T const& t)
  {
    os << t;
  }

  void operator()(type_infos const& t)
  {
    os << "{\n";
    indentation++;
    indent();
    os << "value: "; (*this)(t.value_type); os << ",\n";
    indent();
    os << "container: "; (*this)(t.container); os << ",\n";
    indent();
    os << "settings: {\n";
    indentation++;
    for(std::map<std::string, std::string>::const_iterator it = t.settings.begin(); it != t.settings.end(); ++it)
    {
      indent();
      (*this)(it->first); os << ": "; (*this)(it->second); os << ",\n";
    }
    indentation--;
    indent();
    os << "}\n";
    indentation--;
    indent();
    os << "}";
  }

  void operator()(expression const& e)
  {
    os << "{\n";
    indentation++;
    indent();
    os << "operation: "; (*this)(e.operation); os << ",\n";
    indent();
    os << "type: "; (*this)(e.type); os << ",\n";
    indent();
    os << "children: [\n";
    indentation++;
    for(std::vector<expression>::const_iterator it = e.children.begin(); it != e.children.end(); ++it)
    {
      indent();
      (*this)(*it); os << ",\n";
    }
    indentation--;
    indent();
    os << "]\n";
    indentation--;
    indent();
    os << "}";
  }

  void operator()(tagged_expression const& e)
  {
    os << "{\n";
    indentation++;
    indent();
    os << "raw: "; (*this)(e.raw); os << ",\n";
    indent();
    os << "expr: "; (*this)(e.expr); os << "\n";
    indentation--;
    indent();
    os << "}";
  }

  void operator()(kernel_symbol const& s)
  {
    os << "{\n";
    indentation++;
    indent();
    os << "kernel: "; (*this)(s.kernel); os << ",\n";
    indent();
    os << "target: "; (*this)(s.target); os << ",\n";
    indent();
    os << "arguments: [\n";
    indentation++;
    for(std::vector<tagged_expression>::const_iterator it = s.arguments.begin(); it != s.arguments.end(); ++it)
    {
      indent();
      (*this)(*it); os << ",\n";
    }
    indentation--;
    indent();
    os << "]\n";
    indentation--;
    indent();
    os << "}";
  }

  std::ostream& os;
  std::size_t indentation;
};

inline std::ostream& operator<<(std::ostream& os, type_infos const& t)
{
  pretty_printer(os, 0)(t);
  return os;
}

inline std::ostream& operator<<(std::ostream& os, expression const& e)
{
  pretty_printer(os, 0)(e);
  return os;
}

inline std::ostream& operator<<(std::ostream& os, tagged_expression const& e)
{
  pretty_printer(os, 0)(e);
  return os;
}

inline std::ostream& operator<<(std::ostream& os, kernel_symbol const& s)
{
  pretty_printer(os, 0)(s);
  return os;
}

#endif
