#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

struct Film
{
    string title;
    string director;
    vector<string> actor;
    int yearRelease;
    int durationMinute;
    string genre;
    string mediaType;

    Film() : title(""), director(""), actor({}),
             yearRelease(0), durationMinute(0), genre(""), mediaType("") {}

    Film(string t, string d, vector<string> a, int y, int dur, string g, string m)
        : title(t), director(d), actor(a), yearRelease(y), durationMinute(dur), genre(g), mediaType(m) {}
};

void inputFilm(vector<Film> &f)
{
    int count;
    cout << "Input counts of films: ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        string t, d, g, m;
        int y, dur, actorCount;

        cout << "--- Film " << i + 1 << " ---" << endl;
        cout << "Title: ";
        getline(cin, t);
        cout << "Director: ";
        getline(cin, d);

        cout << "Number of actors: ";
        cin >> actorCount;
        cin.ignore();
        vector<string> actors;
        for (int j = 0; j < actorCount; j++)
        {
            string actor;
            cout << "Actor " << j + 1 << ": ";
            getline(cin, actor);
            actors.push_back(actor);
        }

        cout << "Year of release: ";
        cin >> y;
        cout << "Duration (minutes): ";
        cin >> dur;
        cin.ignore();
        cout << "Genre: ";
        getline(cin, g);
        cout << "Media type (кассета/DVD/MP4): ";
        getline(cin, m);

        f.push_back(Film(t, d, actors, y, dur, g, m));
    }
}

void printFilm(const Film &f)
{
    cout << f.title << "\t" << f.director << "\t";
    for (size_t i = 0; i < f.actor.size(); i++)
    {
        cout << f.actor[i];
        if (i < f.actor.size() - 1)
            cout << ", ";
    }
    cout << "\t" << f.yearRelease << "\t"
         << f.durationMinute << " мин\t"
         << f.genre << "\t" << f.mediaType << endl;
}

void findFilmByGenre(const vector<Film> &film)
{
    string genre;
    cout << "Input genre: ";
    getline(cin, genre);

    bool found = false;
    for (const auto &f : film)
    {
        if (f.genre == genre)
        {
            printFilm(f);
            found = true;
        }
    }

    if (!found)
        cout << "Not found film!" << endl;
}

void findFilmByActor(const vector<Film> &film)
{
    string actor;
    cout << "Input actor: ";
    getline(cin, actor);

    bool found = false;
    for (const auto &f : film)
    {
        for (const auto &a : f.actor)
        {
            if (a == actor)
            {
                printFilm(f);
                found = true;
            }
        }
    }

    if (!found)
        cout << "Not found film!" << endl;
}

void countFileInThisYear(const vector<Film> &film)
{
    int currentYear;
    cout << "Input current year: ";
    cin >> currentYear;
    cin.ignore();

    auto count = count_if(film.begin(), film.end(), [currentYear](const auto &a)
                          { return a.yearRelease == currentYear; });

    cout << "Result counts: " << count << endl;
}

void mostPopularDirector(const vector<Film> &film)
{
    map<string, int> countDirector;

    for (const auto &f : film)
    {
        countDirector[f.director]++;
    }

    auto mostPopular = max_element(countDirector.begin(), countDirector.end(), [](const auto &a, const auto &b)
                                   { return a.second < b.second; });

    cout << "Most popular director: " << mostPopular->first << endl;
}

void mostPopularActor(const vector<Film> &film)
{
    map<string, set<string>> actorGenre;

    for (const auto &f : film)
    {
        for (const auto &a : f.actor)
        {
            actorGenre[a].insert(f.genre);
        }
    }

    auto mostPopularActor = max_element(actorGenre.begin(), actorGenre.end(), [](const auto &a, const auto &b)
                                        { return a.second.size() < b.second.size(); });

    cout << "Most popular actor: " << mostPopularActor->first << endl;
}