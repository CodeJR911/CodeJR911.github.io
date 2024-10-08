#include <iostream>
#include <ctime>
#include <string> // atoi
#include <algorithm>
#include <utility>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

// FIXME (1): Internal structure for tree node
struct Node {
    Bid bid;
    Node* right;
    Node* left;
    Node* parent; //Adding a parent node to make removal easier
    Node() {
        right = left = parent = nullptr;
    }
    explicit Node(Bid bid) : Node() {
        this->bid = std::move(bid);
    }

};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, const Bid& bid);
    void inOrder(Node* node);
    Node* removeNode(Node* node, const string& bidId);
    Node* findMin(Node* node);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void Insert(const Bid& bid);
    void Remove(const string& bidId);
    Bid Search(const string& bidId);
};

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    // initialize housekeeping variables
    root = nullptr;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    // recurse from root deleting every node
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    this->inOrder(root);
}
/**
     * Remove node prive method
     */
Node* BinarySearchTree::removeNode(Node *node, const string& bidId) {
    // If the node is null then return
    if (node == nullptr) {
        return node;
    }
    // Recursively traverse the tree
    if(bidId.compare(node->bid.bidId) < 0) {
        node->left = removeNode(node->left, bidId);
    } else if (bidId.compare(node->bid.bidId) > 0) {
        node->right = removeNode(node->right, bidId);
    } else {
        // Node has no children
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
            // Node has one child
        else if (node->left == nullptr) {
            Node* temp = node->right;
            temp->parent = node->parent; //Set the parents of the child to the nodes parent
            // Determine if the node is on the left or right of the parent
            if(node == node->parent->left) {
                node->parent->left = temp;
            } else {
                node->parent->right = temp;
            }
            delete node;
            node = temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            temp->parent = node->parent; //Set the parents of the child to the nodes parent
            // Determine if the node is on the left or right of the parent
            if(node == node->parent->left) {
                node->parent->left = temp;
            } else {
                node->parent->right = temp;
            }
            delete node;
            node = temp;
        }
            // Node has two children
        else {
            // Find the min value on the right subtree
            Node* temp = findMin(node->right);
            // Copy the values
            node->bid = temp->bid;
            // Remove the min value
            node->right = removeNode(node->right, temp->bid.bidId);
        }
    }
    return node;
}
/**
 * Find the min value in the tree
 */
Node* BinarySearchTree::findMin(Node* node) {
    // Traverse the left subtree until the min is found
    while(node->left != nullptr) {
        node = node->left;
    }
    return node;
}

/**
 * Insert a bid
 */
void BinarySearchTree::Insert(const Bid& bid) {
    // FIXME (2a) Implement inserting a bid into the tree
    // If there is no existing node in the tree
    if(root == nullptr) {
        root = new Node(bid);
    } else {
        // otherwise add it to the root
        this->addNode(root, bid);
    }
}

/**
 * Remove a bid
 */
void BinarySearchTree::Remove(const string& bidId) {
    // FIXME (4a) Implement removing a bid from the tree
    this->removeNode(root, bidId);
}

/**
 * Search for a bid
 */
Bid BinarySearchTree::Search(const string& bidId) {
    // FIXME (3) Implement searching the tree for a bid
    // start from the root
    Node* current = root;
    while(current != nullptr) {
        // If the current node is the one we are looking for
        if(current->bid.bidId == bidId) {
            return current->bid;
        }
        // traverse left if bid is smaller than current
        if(bidId.compare(current->bid.bidId) < 0) {
            current = current->left;
        } else {
            // otherwise traverse right
            current = current->right;
        }
    }


    Bid bid;
    return bid;
}

/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 */
void BinarySearchTree::addNode(Node* node, const Bid& bid) {
    // FIXME (2b) Implement inserting a bid into the tree
    // add to the right if the bid is smaller than the node
    if (node->bid.bidId.compare(bid.bidId) > 0) {
        // If there is no left node
        if(node->left == nullptr) {
            Node* n = new Node(bid);
            n->parent = node; //Set the parent of the new node
            node->left = n;
        } else {
            // Recursively call the function
            this->addNode(node->left, bid);
        }
    } else {
        // add to left if the bid is bigger than the node
        // If there is no right node
        if (node->right == nullptr) {
            Node* n = new Node(bid);
            n->parent = node; //Set the parent of the new node
            node->right = n;
        } else {
            // Recursively call the function
            this->addNode(node->right, bid);
        }
    }

}
// Print the tree in order
void BinarySearchTree::inOrder(Node* node) {
    // Recursively teverse the tree to the right and left and print it as it treverse
    if(node != nullptr) {
        inOrder(node->left);
        cout << node->bid.bidId << ": " << node->bid.title << " | "
        << node->bid.amount << "|" << node->bid.fund << endl;
        inOrder(node->right);
    }
}
//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(const Bid& bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
            << bid.fund << endl;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(const string& csvPath, BinarySearchTree* bst) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            bst->Insert(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        bidKey = "98109";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
        bidKey = "98109";
    }

    // Define a timer variable
    clock_t ticks;

    // Define a binary search tree to hold all bids
    BinarySearchTree* bst;

    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Find Bid" << endl;
        cout << "  4. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            bst = new BinarySearchTree();

            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            loadBids(csvPath, bst);

            //cout << bst->Size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 2:
            bst->InOrder();
            break;

        case 3:
            ticks = clock();

            bid = bst->Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!bid.bidId.empty()) {
                displayBid(bid);
            } else {
            	cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 4:
            bst->Remove(bidKey);
            break;
        }
    }

    cout << "Good bye." << endl;

	return 0;
}
