#ifndef     _CSVPARSER_HPP_
#define    _CSVPARSER_HPP_

#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <sstream>

/**
 * @namespace csv
 * 
 * Namespace for the CSV parser library.
 */
namespace csv
{
    /**
     * @class Error
     * 
     * Custom exception class for CSV parsing errors.
     */
    class Error : public std::runtime_error
    {

      public:
        /**
         * @brief Construct a new Error object
         * 
         * @param msg The error message
         */
        Error(const std::string &msg):
          std::runtime_error(std::string("CSVparser : ").append(msg))
        {
        }
    };

    /**
     * @class Row
     * 
     * Represents a single row in a CSV file.
     */
    class Row
    {
    	public:
        /**
         * @brief Construct a new Row object
         * 
         * @param header A vector of strings representing the header names
         */
    	    Row(const std::vector<std::string> &header);
        /**
         * @brief Destroy the Row object
         * 
         */
    	    ~Row(void);

    	public:
        /**
         * @brief Get the number of values in the row
         * 
         * @return unsigned int The number of values
         */
            unsigned int size(void) const;
        /**
         * @brief Add a new value to the end of the row
         * 
         * @param value The value to add
         */
            void push(const std::string &value);
        /**
         * @brief Set the value of a specific column in the row
         * 
         * @param key The name of the column to set
         * @param value The value to set
         * @return true If the column was successfully set
         * @return false If the column could not be set
         */
            bool set(const std::string &key, const std::string &value); 

    	private:
            // The header row of the CSV file
    		const std::vector<std::string> _header;
            // The values in this row
    		std::vector<std::string> _values;

        public:

            /**
             * @brief Get the value at the specified position in the row, cast to the specified type
             * 
             * @tparam T The type to cast the value to
             * @param pos The position of the value to return
             * @return const T The value
             */
            template<typename T>
            const T getValue(unsigned int pos) const
            {
                if (pos < _values.size())
                {
                    T res;
                    std::stringstream ss;
                    ss << _values[pos];
                    ss >> res;
                    return res;
                }
                throw Error("can't return this value (doesn't exist)");
            }
            /**
             * @brief Get the value at the specified position in the row
             * 
             * @param valuePosition The position of the value to return
             * @return const std::string The value
             */
            const std::string operator[](unsigned int) const;
            /**
             * @brief Get the value of the specified column
             * 
             * @param key The name of the column to return the value of
             * @return const std::string The value
             */
            const std::string operator[](const std::string &valueName) const;
            // Overloads the << operator for printing a Row object to an ostream
            friend std::ostream& operator<<(std::ostream& os, const Row &row);
            // Overloads the << operator for printing a Row object to an ofstream
            friend std::ofstream& operator<<(std::ofstream& os, const Row &row);
    };

    /**
     * @enum DataType
     * 
     * Specifies the type of data being parsed.
     */
    enum DataType {
        eFILE = 0, // Data is read from a file
        ePURE = 1  // Data is a string
    };

    /**
     * @class Parser
     * 
     * Parses CSV data from a file or string.
     */
    class Parser
    {

    public:
        /**
         * @brief Construct a new Parser object
         * 
         * @param data The data to parse, either a file path or a string containing the data
         * @param type The type of data being parsed, either a file or a string
         * @param sep The separator character to use, defaults to ','
         */
        Parser(const std::string &data, const DataType &type = eFILE, char sep = ',');
        /**
         * @brief Destroy the Parser object
         * 
         */
        ~Parser(void);

    public:
        /**
         * @brief Get the Row object at the specified position
         * 
         * @param row The position of the row to return
         * @return Row& A reference to the Row object
         */
        Row &getRow(unsigned int row) const;
        /**
         * @brief Get the number of rows in the CSV data
         * 
         * @return unsigned int The number of rows
         */
        unsigned int rowCount(void) const;
        /**
         * @brief Get the number of columns in the CSV data
         * 
         * @return unsigned int The number of columns
         */
        unsigned int columnCount(void) const;
        /**
         * @brief Get a vector of the header names
         * 
         * @return std::vector<std::string> The header names
         */
        std::vector<std::string> getHeader(void) const;
        /**
         * @brief Get the header name at the specified position
         * 
         * @param pos The position of the header name to return
         * @return const std::string The header name
         */
        const std::string getHeaderElement(unsigned int pos) const;
        /**
         * @brief Get the file name used to initialize the Parser
         * 
         * @return const std::string& The file name
         */
        const std::string &getFileName(void) const;

    public:
        /**
         * @brief Delete the row at the specified position
         * 
         * @param row The position of the row to delete
         * @return true If the row was successfully deleted
         * @return false If the row could not be deleted
         */
        bool deleteRow(unsigned int row);
        /**
         * @brief Add a new row at the specified position
         * 
         * @param pos The position to insert the new row at
         * @param r A vector of strings representing the new row
         * @return true If the row was successfully added
         * @return false If the row could not be added
         */
        bool addRow(unsigned int pos, const std::vector<std::string> &r);
        /**
         * @brief Syncs the parsed data back to the original file
         * 
         * If the Parser was initialized with a file path, this method will overwrite the original file
         * with the parsed data.
         */
        void sync(void) const;

    protected:
        /**
         * @brief Parses the header row of the CSV data
         * 
         */
    	void parseHeader(void);
        /**
         * @brief Parses the content rows of the CSV data
         * 
         */
    	void parseContent(void);

    private:
        // The file name of the CSV file
        std::string _file;
        // The type of data being parsed
        const DataType _type;
        // The separator character
        const char _sep;
        // The original CSV data, stored as a vector of strings
        std::vector<std::string> _originalFile;
        // The header row of the CSV file
        std::vector<std::string> _header;
        // The content rows of the CSV file
        std::vector<Row *> _content;

    public:
        /**
         * @brief Get the Row object at the specified position
         * 
         * @param row The position of the row to return
         * @return Row& A reference to the Row object
         */
        Row &operator[](unsigned int row) const;
    };
}

#endif /*!_CSVPARSER_HPP_*/
