
#include <stdio.h>

// Forward declaration using typedef to make type Node
typedef struct node Node;

struct node {
	char * name;
	int value;
};

struct pixel {
	Node n; // structs can contain structs. "struct node n"; would also work here
	int x; 
	int y;
} Pixel = { {"node 0", 1} , 2, 3}; // create a struct straight after defining one
                                   // the inner brackets assign to Node n
                                   // the outer to int x, int y

// create a function that returns a pixel struct
 struct pixel CreatePixel(Node n, int x, int y) {
 	struct pixel p = {n, x, y};
 	return p;
 }

int main() {
	Node Nodes[3] = 
	{ // an array of 3 Nodes. assigning values below
		{"first", 1},
		{"second", 2},
		{"third", 3},
	};
	Node * head = Nodes; // Node pointer to base address of Nodes
	int c; 
	for (c = 0; c < 3; c++) {
		printf("%s %s %d %d\n", head->name, Nodes[c].name, head->value, Nodes[c].value);
		head++; // increment head pointer. Can also use " (head++)->name " above
	}
	printf("\n");
	struct pixel newpixel = CreatePixel(Nodes[0], 5, 10);
	printf("%s %d, %d %d\n", Pixel.n.name, Pixel.n.value, Pixel.x, Pixel.y); // Pixel defined earlier
	printf("%s %d, %d %d\n", newpixel.n.name, newpixel.n.value, newpixel.x, newpixel.y);
	return 0;
}
