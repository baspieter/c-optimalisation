#include "precomp.h" // include (only) this in every .cpp file


// Partition krijgt telkens een kant van de boom.
// Wisselt tanks op basis van de laatste tank.
// Hierdoor staat de laatste tank op de juiste plek.
// Stuurt de positie van de tank die op de juiste plek staat terug.
int Partition(vector<Tank>& tanks, int start, int end) {

    int last = end;
    int first = start;
    for (int i = start; i < end; ++i) {
        if (tanks[i].health < tanks[last].health) {
            swap(tanks[i], tanks[first]);
            ++first;
        }
    }
    swap(tanks[first], tanks[last]);
    return first;

}

// Quicksort krijgt de tank die op de juiste plek staat terug.
// Splitst het in twee kanten en laat die weer door partition uitvoeren.
// Op de gegeven moment zijn er alleen maar boom waardes met 1 value.
// Die worden achter elkaar aan gezet, wat een gesorteerde lijs creert.
void Quicksort(vector<Tank>& tanks, int start, int end) {
    if (start < end) {
        int p = Partition(tanks, start, end);
        Quicksort(tanks, start, p - 1);
        Quicksort(tanks, p + 1, end);
    }
}