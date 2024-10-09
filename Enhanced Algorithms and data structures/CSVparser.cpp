#include <fstream>
#include <sstream>
#include <iomanip>
#include "CSVparser.hpp"

namespace csv {

  /**
   * @brief Construct a new Parser object
   * 
   * @param data The data to parse, either a file path or a string containing the data
   * @param type The type of data being parsed, either a file or a string
   * @param sep The separator character to use, defaults to ','
   */
  Parser::Parser(const std::string &data, const DataType &type, char sep)
    : _type(type), _sep(sep)
  {
      std::string line;
      // Check if the data is a file path or a string
      if (type == eFILE)
      {
        // If it's a file path, store the file name
        _file = data;
        // Open the file for reading
        std::ifstream ifile(_file.c_str());
        // Check if the file is open
        if (ifile.is_open())
        {
            // Read the file line by line
            while (ifile.good())
            {
                getline(ifile, line);
                // Only add the line if it's not empty
                if (!line.empty()) {
                    _originalFile.push_back(line);
                }
            }
            // Close the file
            ifile.close();

            // If the file is empty, throw an error
            if (_originalFile.empty())
              throw Error(std::string("No Data in ").append(_file));
            
            // Parse the header row
            parseHeader();
            // Parse the content rows
            parseContent();
        }
        else
            // If the file could not be opened, throw an error
            throw Error(std::string("Failed to open ").append(_file));
      }
      else
      {
        // If the data is a string, create a stringstream from it
        std::istringstream stream(data);
        // Read the stringstream line by line
        while (std::getline(stream, line))
          // Only add the line if it's not empty
          if (line != "")
            _originalFile.push_back(line);
        // If the stringstream is empty, throw an error
        if (_originalFile.empty())
          throw Error(std::string("No Data in pure content"));

        // Parse the header row
        parseHeader();
        // Parse the content rows
        parseContent();
      }
  }

  /**
   * @brief Destroy the Parser object
   * 
   * Iterates through the _content vector and deletes each Row object.
   */
  Parser::~Parser(void)
  {
     for (auto & it : _content) {
          delete it;
     }
  }

  /**
   * @brief Parses the header row of the CSV data
   * 
   * Splits the first row of the _originalFile vector by the separator character
   * and stores each element in the _header vector.
   */
  void Parser::parseHeader(void)
  {
      // Create a stringstream from the first row of the _originalFile vector
      std::stringstream ss(_originalFile[0]);
      std::string item;

      // Split the stringstream by the separator character
      while (std::getline(ss, item, _sep)) {
          // Add each element to the _header vector
          _header.push_back(item);
      }
  }

  /**
   * @brief Parses the content rows of the CSV data
   * 
   * Iterates through the _originalFile vector, skipping the header row.
   * For each row, it splits the row by the separator character and stores each element in a Row object.
   * The Row object is then added to the _content vector.
   */
  void Parser::parseContent(void)
  {
     // Skip the header row
     for (auto it = _originalFile.begin() + 1; it != _originalFile.end(); it++)
     {
         // Flag to keep track of whether we are currently inside a quoted string
         bool quoted = false;
         // Index of the start of the current token
         int tokenStart = 0;

         // Create a new Row object
         Row *row = new Row(_header);

         // Iterate through each character in the row
         for (unsigned int i = 0; i != it->length(); i++)
         {
              // If the character is a quote, toggle the quoted flag
              if (it->at(i) == '"') {
                  quoted = !quoted;
              } else if (it->at(i) == ',' && !quoted) {
                  // If the character is a separator and we're not inside a quote,
                  // extract the substring from the last separator or the start of the row
                  // to the current position and add it to the row
                  row->push(it->substr(tokenStart, i - tokenStart));
                  // Update the token start index
                  tokenStart = i + 1;
              }
         }

         // Extract the last token from the last separator to the end of the row
         row->push(it->substr(tokenStart, it->length() - tokenStart));

         // If the number of values in the row doesn't match the number of headers,
         // throw an error
         if (row->size() != _header.size()) {
          throw Error("corrupted data !");
         }
         // Add the row to the content vector
         _content.push_back(row);
     }
  }

  /**
   * @brief Returns a reference to the Row object at the specified position
   * 
   * @param rowPosition The position of the row to return
   * @return Row& A reference to the Row object
   */
  Row &Parser::getRow(unsigned int rowPosition) const
  {
      // Check if the row position is valid
      if (rowPosition < _content.size())
          return *(_content[rowPosition]);
      // If the row position is invalid, throw an error
      throw Error("can't return this row (doesn't exist)");
  }

  /**
   * @brief Returns a reference to the Row object at the specified position
   * 
   * @param rowPosition The position of the row to return
   * @return Row& A reference to the Row object
   */
  Row &Parser::operator[](unsigned int rowPosition) const
  {
      return Parser::getRow(rowPosition);
  }

  /**
   * @brief Returns the number of rows in the CSV data
   * 
   * @return unsigned int The number of rows
   */
  unsigned int Parser::rowCount(void) const
  {
      return _content.size();
  }

  /**
   * @brief Returns the number of columns in the CSV data
   * 
   * @return unsigned int The number of columns
   */
  unsigned int Parser::columnCount(void) const
  {
      return _header.size();
  }

  /**
   * @brief Returns a vector of the header names
   * 
   * @return std::vector<std::string> The header names
   */
  std::vector<std::string> Parser::getHeader(void) const
  {
      return _header;
  }

  /**
   * @brief Returns the header name at the specified position
   * 
   * @param pos The position of the header name to return
   * @return const std::string The header name
   */
  const std::string Parser::getHeaderElement(unsigned int pos) const
  {
      // Check if the position is valid
      if (pos >= _header.size())
        throw Error("can't return this header (doesn't exist)");
      return _header[pos];
  }

  /**
   * @brief Deletes the row at the specified position
   * 
   * @param pos The position of the row to delete
   * @return true If the row was successfully deleted
   * @return false If the row could not be deleted
   */
  bool Parser::deleteRow(unsigned int pos)
  {
    // Check if the position is valid
    if (pos < _content.size())
    {
      // Delete the Row object at the specified position
      delete *(_content.begin() + pos);
      // Erase the element from the vector
      _content.erase(_content.begin() + pos);
      return true;
    }
    return false;
  }

  /**
   * @brief Adds a new row at the specified position
   * 
   * @param pos The position to insert the new row at
   * @param r A vector of strings representing the new row
   * @return true If the row was successfully added
   * @return false If the row could not be added
   */
  bool Parser::addRow(unsigned int pos, const std::vector<std::string> &r)
  {
    // Create a new Row object
    Row *row = new Row(_header);

    // Add each value to the row
    for (auto it = r.begin(); it != r.end(); it++)
      row->push(*it);
    
    // Check if the position is valid
    if (pos <= _content.size())
    {
      // Insert the new row at the specified position
      _content.insert(_content.begin() + pos, row);
      return true;
    }
    return false;
  }

  /**
   * @brief Syncs the parsed data back to the original file
   * 
   * If the Parser was initialized with a file path, this method will overwrite the original file
   * with the parsed data.
   */
  void Parser::sync(void) const
  {
    // Check if the Parser was initialized with a file path
    if (_type == DataType::eFILE)
    {
      // Open the file for writing
      std::ofstream f;
      f.open(_file, std::ios::out | std::ios::trunc);

      // Write the header row
      unsigned int i = 0;
      for (auto it = _header.begin(); it != _header.end(); it++)
      {
        f << *it;
        // Add a comma after each header except the last one
        if (i < _header.size() - 1)
          f << ",";
        else
          f << std::endl;
        i++;
      }
     
      // Write the content rows
      for (auto it = _content.begin(); it != _content.end(); it++) {
        f << **it << std::endl;
      }
      // Close the file
      f.close();
    }
  }

  /**
   * @brief Returns the file name used to initialize the Parser
   * 
   * @return const std::string& The file name
   */
  const std::string &Parser::getFileName(void) const
  {
      return _file;    
  }
  
  /*
  ** ROW
  */

  /**
   * @brief Construct a new Row object
   * 
   * @param header A vector of strings representing the header names
   */
  Row::Row(const std::vector<std::string> &header)
      : _header(header) {}

  Row::~Row(void) {}

  /**
   * @brief Returns the number of values in the row
   * 
   * @return unsigned int The number of values
   */
  unsigned int Row::size(void) const
  {
    return _values.size();
  }

  /**
   * @brief Adds a new value to the end of the row
   * 
   * @param value The value to add
   */
  void Row::push(const std::string &value)
  {
    _values.push_back(value);
  }

  /**
   * @brief Sets the value of a specific column in the row
   * 
   * @param key The name of the column to set
   * @param value The value to set
   * @return true If the column was successfully set
   * @return false If the column could not be set
   */
  bool Row::set(const std::string &key, const std::string &value) 
  {
    // Find the index of the column with the matching name
    auto it = std::find(_header.begin(), _header.end(), key);
    if (it != _header.end()) {
        // Calculate the index of the column
        int pos = std::distance(_header.begin(), it);
        // Set the value at the calculated index
        _values[pos] = value;
        return true;
    }
    return false;
  }

  /**
   * @brief Returns the value at the specified position in the row
   * 
   * @param valuePosition The position of the value to return
   * @return const std::string The value
   */
  const std::string Row::operator[](unsigned int valuePosition) const
  {
       // Check if the position is valid
       if (valuePosition < _values.size())
           return _values[valuePosition];
       // If the position is invalid, throw an error
       throw Error("can't return this value (doesn't exist)");
  }

  /**
   * @brief Returns the value of the specified column
   * 
   * @param key The name of the column to return the value of
   * @return const std::string The value
   */
  const std::string Row::operator[](const std::string &key) const
  {
      // Find the index of the column with the matching name
      auto it = std::find(_header.begin(), _header.end(), key);
      if (it != _header.end()) {
          // Calculate the index of the column
          int pos = std::distance(_header.begin(), it);
          // Return the value at the calculated index
          return _values[pos];
      }
      
      throw Error("can't return this value (doesn't exist)");
  }

  /**
   * @brief Overloads the << operator for printing a Row object to an ostream
   * 
   * @param os The ostream to print to
   * @param row The Row object to print
   * @return std::ostream& The ostream
   */
  std::ostream &operator<<(std::ostream &os, const Row &row)
  {
      for (unsigned int i = 0; i != row._values.size(); i++)
          os << row._values[i] << " | ";

      return os;
  }

  /**
   * @brief Overloads the << operator for printing a Row object to an ofstream
   * 
   * @param os The ofstream to print to
   * @param row The Row object to print
   * @return std::ofstream& The ofstream
   */
  std::ofstream &operator<<(std::ofstream &os, const Row &row)
  {
    for (unsigned int i = 0; i != row._values.size(); i++)
    {
        os << row._values[i];
        // Add a comma after each value except the last one
        if (i < row._values.size() - 1)
          os << ",";
    }
    return os;
  }
}
