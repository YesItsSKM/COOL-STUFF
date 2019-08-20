#include <iostream>     // For basic I/O.
#include <fstream>      // For writing data to file - [open(), close()].
#include <string.h>     // For string manipulation.
#include "graph.hpp"    // Graph implementation C++ header file.

using namespace std;    // Standard namespace - [Basically to remove ambiguity of cout, cin, cerr].

// main/driver funcion
int main(int argc, char const *argv[]){
    fstream file;   // Declaring a file stream object. This would be the .dot file; The file in which details of the graph should be written.

    string file_name;       // String object to store filename(without extension).

    cout << "Enter filename : ";
    cin >> file_name;

    const char* file_name_ptr = file_name.c_str();      // Converting string object to const char*.

    strcat((char *)file_name_ptr, ".dot");              // Providing the correct extension to the file. This file would be read by the GraphViz library to generate(visualize) the graph.

    int choice, staring_node, ending_node, weight;

    cout << "\nEnter which type of graph you need to make : ";
    cout << "\n\t1. Undirectional graph.";
    cout << "\n\t2. Directional graph.";
    cout << "\n>> ";
	cin >> choice;

    int number_of_nodes = 0;
	cout << "\nEnter number of nodes : ";
	cin >> number_of_nodes;

	Graph myGraph(number_of_nodes);     // Creating graph object with given number of node. Remember not to enter a node with (Value > Number_of_nodes).

    file.open(file_name, ios::out);         // Opening the file, to write the details of graph.

    char ch_weight = 'y', ch_again = 'y';

    if(file.is_open()){
        // Writing into the file.

        cout << "\n[FILE IS OPEN.]\n";

        switch(choice){
            case 1 :
                    file << "graph MyGraph{\n";

                    cout << "\nDo you want to add weights to the edges(Y/N)?\n>> ";
                    cin >> ch_weight;

                    if((ch_weight == 'y') || (ch_weight == 'Y')){
                            while(ch_again == 'y' || ch_again == 'Y'){
                            cout << "\nEnter (Starting_node, Ending_node, Weight) of the edge : ";
                            cin >> staring_node >> ending_node >> weight;

                            if((staring_node > number_of_nodes) || (ending_node > number_of_nodes)){
                                cout << "\n[ SORRY, NODE EXCEEDED MAXIMUM VALUE(Number_of_nodes) | TERMINATING PROGRAM. ]\n";

                                char command[6] = "rm ";

                                strcat(command, file_name_ptr);
                                system(command);    // Executing the command to remove the file.

                                cout << "\n[ CHANGES REVERTED | FILE DELETED. ]\n";

                                exit(0);
                            }

                            myGraph.addEdge(staring_node, ending_node, weight);
                        
                            file << "\t" << staring_node << " -- " << ending_node << "[label=\"" << weight << "\",weight=\"" << weight << "\"];" << endl;

                            cout << "\nAdd edge(Y/N)?\n>> ";
                            cin >> ch_again;
                        }

                        file << "}" << endl;
                    }
                    else if((ch_weight == 'n') || (ch_weight == 'N')){
                        while(ch_again == 'y' || ch_again == 'Y'){
                            cout << "\nEnter (Starting_node, Ending_node) of the edge : ";
                            cin >> staring_node >> ending_node;

                            if((staring_node > number_of_nodes) || (ending_node > number_of_nodes)){
                                cout << "\n[ SORRY, NODE EXCEEDED MAXIMUM VALUE(Number_of_nodes) | TERMINATING PROGRAM. ]\n";

                                char command[6] = "rm ";

                                strcat(command, file_name_ptr);
                                system(command);    // Executing the command to remove the file.

                                cout << "\n[ CHANGES REVERTED | FILE DELETED. ]\n";

                                exit(0);
                            }

                            myGraph.addEdge(staring_node, ending_node, 0);
                        
                            file << "\t" << staring_node << " -- " << ending_node << endl;

                            cout << "\nAdd edge(Y/N)?\n>> ";
                            cin >> ch_again;
                        }

                        file << "}" << endl;
                    }
                    else
                        cout << "\nINVALID CHOICE.";
                        
                        break;

                case 2 :
                    file << "digraph MyGraph{\n";

                    cout << "\nDo you want to add weights to the edges(Y/N)?\n>> ";
                    cin >> ch_weight;

                    if((ch_weight == 'y') || (ch_weight == 'Y')){
                        while(ch_again == 'y' || ch_again == 'Y'){
                            cout << "\nEnter (Starting_node, Ending_node, Weight) of the edge : ";
                            cin >> staring_node >> ending_node >> weight;

                            if((staring_node > number_of_nodes) || (ending_node > number_of_nodes)){
                                cout << "\n[ SORRY, NODE EXCEEDED MAXIMUM VALUE(Number_of_nodes) | TERMINATING PROGRAM. ]\n";

                                char command[6] = "rm ";

                                strcat(command, file_name_ptr);
                                system(command);    // Executing the command to remove the file.

                                cout << "\n[ CHANGES REVERTED | FILE DELETED. ]\n";

                                exit(0);
                            }

                            myGraph.addEdge(staring_node, ending_node, weight);
                        
                            file << "\t" << staring_node << " -> " << ending_node << "[label=\"" << weight << "\",weight=\"" << weight << "\"];" << endl;

                            cout << "\nAdd edge(Y/N)?\n>> ";
                            cin >> ch_again;
                        }

                            file << "}" << endl;
                    }

                    else if((ch_weight == 'n') || (ch_weight == 'N')){
                        while(ch_again == 'y' || ch_again == 'Y'){
                            cout << "\nEnter (Starting_node, Ending_node) of the edge : ";
                            cin >> staring_node >> ending_node;

                            if((staring_node > number_of_nodes) || (ending_node > number_of_nodes)){
                                cout << "\n[ SORRY, NODE EXCEEDED MAXIMUM VALUE(Number_of_nodes) | TERMINATING PROGRAM. ]\n";

                                char command[6] = "rm ";

                                strcat(command, file_name_ptr);
                                system(command);    // Executing the command to remove the file.

                                cout << "\n[ CHANGES REVERTED | FILE DELETED. ]\n";

                                exit(0);
                            }

                            myGraph.addEdge(staring_node, ending_node, 0);
                        
                            file << "\t" << staring_node << " -> " << ending_node << endl;

                            cout << "\nAdd edge(Y/N)?\n>> ";
                            cin >> ch_again;
                        }

                            file << "}" << endl;
                    }

                    else
                        cout << "\n[ INVALID CHOICE. ]";

                        break;
                    
                default : cout << "\n[ INVALID CHOICE. ]";
                }
    }

    else{
        cerr << "[ UNABLE TO OPEN FILE... (" << file_name << ".dot) ]";
        char command[6] = "rm ";

        strcat(command, file_name_ptr);
        system(command);    // Executing the command to remove the file.

        cout << "\n[ CHANGES REVERTED | FILE DELETED. ]\n";
    }

    file.close();
    cout << "\n[ CHANGES SAVED | FILE IS CLOSED. ]\n";

    char command[30] = "circo -Tpng -O ";

    const char* ptr = file_name.c_str();

    strcat(command, ptr);
    system(command);    // Executing the command to generate a .png file of the respective graph.

    char command2[30] = "xdg-open ";

    strcat(command2, ptr);
    strcat(command2, ".png");
    system(command2);   // Executing the command to show the graph.

    cout << "\n[ GRAPH VISUALIZED. ]\n";

    return 0;
}