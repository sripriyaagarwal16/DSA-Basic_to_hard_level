#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Song {
    int singer;
    int length;
};

bool compareSongs(const Song &a, const Song &b) {
    return (a.length * b.singer) > (b.length * a.singer);
}

long int getMaxFun(vector<int> singer, vector<int> length) {
    int n = singer.size();
    vector<Song> songs(n);

    // Populate the vector of songs
    for (int i = 0; i < n; ++i) {
        songs[i].singer = singer[i];
        songs[i].length = length[i];
    }

    // Sort the songs based on the fun amount
    sort(songs.begin(), songs.end(), compareSongs);

    long int maxFun = 0;
    long int totalSingers = 0;
    unordered_set<int> uniqueSingers;

    // Calculate the maximum fun
    for (int i = 0; i < n; ++i) {
        uniqueSingers.insert(songs[i].singer);
        totalSingers += uniqueSingers.size() * songs[i].length;
        maxFun += totalSingers;
    }

    return maxFun;
}

int main() {
    int n;
    cout << "Enter the number of songs: ";
    cin >> n;

    vector<int> singer(n);
    cout << "Enter the singers: ";
    for (int i = 0; i < n; ++i) {
        cin >> singer[i];
    }

    vector<int> length(n);
    cout << "Enter the lengths: ";
    for (int i = 0; i < n; ++i) {
        cin >> length[i];
    }

    // Calculate and print the maximum fun
    cout << "Maximum fun: " << getMaxFun(singer, length) << endl;

    return 0;
}
