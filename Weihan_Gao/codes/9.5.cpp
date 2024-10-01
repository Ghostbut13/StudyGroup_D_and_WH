#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<string> CriticsPick(map<string, double> moviesList);

int main() {
    map<std::string, double> moviesList = {
    {"The Pianist", 8.5},
    {"The Green Mile", 8.6},
    {"American History X", 8.5},
    {"12 Angry Men", 8.9},
    {"Leon: The Professional", 8.5},
    {"The Silence of the Lambs", 8.6},
    {"The Usual Suspects", 8.5},
    {"Fight Club", 8.8},
    {"The Lion King", 8.5},
    {"Parasite", 8.5},
    {"It's a Wonderful Life", 8.6},
    {"Goodfellas", 8.7},
    {"The Matrix", 8.7},
    {"Forrest Gump", 8.8},
    {"The Godfather", 9.2},
    {"The Lord of the Rings: The Return of the King", 8.9},
    {"Spirited Away", 8.6},
    {"The Dark Knight", 9.0},
    {"The Shawshank Redemption", 9.3},
    {"City of God", 8.6},
    {"Schindler's List", 8.9},
    {"The Empire Strikes Back", 8.7},
    {"Inception", 8.7},
    {"Interstellar", 8.6},
    {"Life Is Beautiful", 8.6},
    {"Saving Private Ryan", 8.6},
    {"Se7en", 8.6},
    {"One Flew Over the Cuckoo's Nest", 8.7},
    {"Pulp Fiction", 8.8},
    {"Gladiator", 8.5}
    };
    set<string> myBest10 = CriticsPick(moviesList);
    for (set<string>::iterator itr = myBest10.begin(); itr != myBest10.end(); ++itr) {
        cout << *itr << endl;
    }
    return 0;
}

set<string> CriticsPick(map<string, double> moviesList) {

    vector<pair<string, double> > myMovie(
        moviesList.begin(),
        moviesList.end()
    );

    sort(myMovie.begin(),
        myMovie.end(),
        [](pair<string, double> a, pair<string, double> b) {return a.second > b.second; });

    set<string> myBest10;
    for (vector< pair<string, double> >::iterator itr = myMovie.begin(); itr != myMovie.begin() + 10; ++itr) {
        myBest10.insert(itr->first);
    }

    return myBest10;
}