// by watercolor, 2023-06-19

int largestAltitude(int* gain, int gainSize)
{
    int altitude = 0, largest = 0;

    for(int i = 0; i < gainSize; i++) {
        altitude += gain[i];
        if(altitude > largest) {
            largest = altitude;
        }
    }

    return largest;
}
