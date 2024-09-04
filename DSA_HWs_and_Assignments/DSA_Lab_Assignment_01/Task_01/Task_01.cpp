#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Queue.h"
#include "Queue.cpp"
using namespace std;

int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

// Function to print the environment array
void PrintEnvironment(int **array, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << (array[i][j] == -1 ? "#" : to_string(array[i][j])) << "\t";
        }
        cout << endl;
    }
}

// Function to check if a position is inside the environment bounds
bool IsInsideBounds(int x, int y, int width, int height)
{
    return x >= 0 && x < width && y >= 0 && y < height;
}

// Function to perform the wave algorithm
void PerformWave(int **environment, int width, int height, int startX, int startY)
{
    Queue<pair<int, int>> waveQueue;
    waveQueue.enQueue({startX, startY});

    int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
    int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

    while (!waveQueue.isEmpty())
    {
        pair<int, int> current = waveQueue.getElementAtFront();
        waveQueue.deQueue();

        for (int i = 0; i < 8; i++)
        {
            int newX = current.first + dx[i];
            int newY = current.second + dy[i];

            if (IsInsideBounds(newX, newY, width, height) && environment[newY][newX] == 0)
            {
                environment[newY][newX] = environment[current.second][current.first] + 1;
                waveQueue.enQueue({newX, newY});
            }
        }
    }
}

// Function to find and print the path
void FindAndPrintPath(int **environment, char **path, int width, int height, int startX, int startY, int goalX, int goalY)
{
    int x = goalX;
    int y = goalY;

    while (x != startX || y != startY)
    {
        int minVal = environment[y][x];
        int nextX = x;
        int nextY = y;

        for (int i = 0; i < 8; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (IsInsideBounds(newX, newY, width, height) && environment[newY][newX] < minVal)
            {
                minVal = environment[newY][newX];
                nextX = newX;
                nextY = newY;
            }
        }

        path[nextY][nextX] = '*';
        x = nextX;
        y = nextY;
    }

    // Print the path
    cout << "Path Found:" << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << path[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int width, height, percentImpassible;

    // Seed the random number generator
    srand(time(0));

    // Welcome message and input prompts
    cout << "Welcome to WaveFront Pather" << endl;
    cout << "Please tell me about the grid you want to generate. Enter the width (at least 10): ";
    cin >> width;
    cout << "Enter the height (at least 10): ";
    cin >> height;

    // Check if the size of the grid is at least 10x10
    if (width < 10 || height < 10)
    {
        cout << "Grid size must be at least 10x10. Exiting." << endl;
        return 1;
    }

    // Dynamically allocate the environment array and path array
    int **environment = new int *[height];
    char **path = new char *[height];
    for (int i = 0; i < height; i++)
    {
        environment[i] = new int[width];
        path[i] = new char[width];
        for (int j = 0; j < width; j++)
        {
            environment[i][j] = 0;
            path[i][j] = ' ';
        }
    }

    // Input prompt for the percentage of impassible terrain
    cout << "Enter the percent of impassible terrain (0 - 100): ";
    cin >> percentImpassible;

    // Check if the percentage is greater than 35%
    if (percentImpassible > 35)
    {
        char choice;
        cout << "Having a value greater than 35% might create poor results. Do you wish to continue? (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y')
        {
            cout << "Exiting." << endl;
            return 1;
        }
    }

    // Generate impassible terrain based on percentage
    int impassibleCount = (width * height * percentImpassible) / 100;
    while (impassibleCount > 0)
    {
        int x = rand() % width;
        int y = rand() % height;

        if (environment[y][x] != -1)
        {
            environment[y][x] = -1;
            impassibleCount--;
        }
    }

    // Print the environment
    cout << "Generated Environment:" << endl;
    PrintEnvironment(environment, width, height);

    // Input prompt for goal position
    int goalX, goalY;
    cout << "Please enter the Goal Position X: ";
    cin >> goalX;
    cout << "Please enter the Goal Position Y: ";
    cin >> goalY;

    // Check if the goal position is valid
    if (!IsInsideBounds(goalX, goalY, width, height) || environment[goalY][goalX] == -1)
    {
        cout << "Sorry, that position is inside an obstacle. Exiting." << endl;
        return 1;
    }

    // Set the goal position in the environment
    environment[goalY][goalX] = 1;

    // Input prompt for start position
    int startX, startY;
    cout << "Please enter the Start Position X: ";
    cin >> startX;
    cout << "Please enter the Start Position Y: ";
    cin >> startY;

    // Check if the start position is valid
    if (!IsInsideBounds(startX, startY, width, height) || environment[startY][startX] == -1)
    {
        cout << "Sorry, that position is inside an obstacle. Exiting." << endl;
        return 1;
    }

    // Set the start position in the environment
    environment[startY][startX] = 1;

    // Perform the wave algorithm
    PerformWave(environment, width, height, goalX, goalY);

    // Find and print the path
    FindAndPrintPath(environment, path, width, height, startX, startY, goalX, goalY);

    // Clean up dynamically allocated memory
    for (int i = 0; i < height; i++)
    {
        delete[] environment[i];
        delete[] path[i];
    }
    delete[] environment;
    delete[] path;

    return 0;
}