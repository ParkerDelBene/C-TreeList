Author: Parker DelBene
Date Created: 10/01/21


The Purpose of this program is to define a TreeList data structure, which uses a custom Node struct that combines a Linked List with a Binary Tree.

The way this is achieved is with slightly more memory allocation than either a Binary Tree or Linked List but better than having one of each. It uses
a custome Node which holds the next Node in the List as well as Nodes directly less and greater than. This will allow for Binary sorting of the 
Linked List portion as well as hot swapping between least to greatest and greatest to least orders for the Linked List. I am hoping that this will 
speed up the time it takes to output data from a Binary Tree by holding that data in a Binary sorted Linked List.

This concept could be done by sorting the items as you are entering them into the Linked List, but the time it would take for large data sets to do 
this is outweighed by the versatility of having the two combined. This structure takes up more space than just a Linked List or Binary Tree, but it
is negligable as the extra data is just references to other data sets.

The inclusion of iostream is only to be used with the included driver, if no output from the system is needed than the inclusion of iostream can be taken away.
Hopefully I will have a version of this class that is templated so as to allow for any data type to be included into the list.

