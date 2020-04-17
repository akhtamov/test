#include "container.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>
using namespace std;

list * ptrHead = nullptr;
list * ptrCur = nullptr;

struct list * list_init()
{
    ptrHead = new struct list;
    ptrCur = new struct list;
    ptrHead->next = ptrHead;
    ptrHead->prev = ptrHead;
    ptrCur = ptrHead;
    return ptrCur;
}

struct list * add_to_list()
{
    struct list *ptrNew;
    ptrNew = new struct list;

    ptrNew->next = ptrHead;
    ptrNew->prev = ptrCur->prev;
    ptrCur->prev->next = ptrNew;
    ptrCur->prev = ptrNew;

    return ptrNew;
}

bool readFile(string input)
{
    ifstream file(input);
    if (!file.is_open())
    {
        return false;
    }
    string line;
    getline(file, line);
    int figuresCount = atoi(line.c_str());
    for (int i = 0; i < figuresCount; i++)
    {
        if (i == 0)
        {
            ptrHead = list_init();
            ptrCur = ptrHead;
        }
        else
            ptrCur = add_to_list();

        getline(file, line);
        ptrCur->shp.type = atoi(line.c_str());

        getline(file, line);
        ptrCur->shp.color = atoi(line.c_str());

        if (ptrCur->shp.type == CIRCLE)
        {
            getline(file, line);
            ptrCur->shp.xCenter = atoi(line.c_str());

            getline(file, line);
            ptrCur->shp.yCenter = atoi(line.c_str());

            getline(file, line);
            ptrCur->shp.radius = atoi(line.c_str());
        }
        else
        {
            getline(file, line);
            ptrCur->shp.xLeftUpCorner = atoi(line.c_str());

            getline(file, line);
            ptrCur->shp.yLeftUpCorner = atoi(line.c_str());

            getline(file, line);
            ptrCur->shp.xRightDownCorner = atoi(line.c_str());

            getline(file, line);
            ptrCur->shp.yRightDownCorner = atoi(line.c_str());
        }

    }
    return true;
}

bool writeToFile(string output) {
    ofstream outfile(output);
    if (!outfile.is_open()) {
        return false;
    }
    int figuresCount = 0;
    list *ptrTemp = ptrHead;
    string color;
    do {
        if (ptrTemp->shp.type == CIRCLE) {
            outfile << "Type of shape is CIRCLE" << endl;
            outfile << "Center's coordinates are (" << ptrTemp->shp.xCenter << ", " << ptrTemp->shp.yCenter << ")"
                    << endl;
            outfile << "Radius is " << ptrTemp->shp.radius << endl;
        } else if (ptrTemp->shp.type == RECTANGLE) {
            outfile << "Type of shape is RECTANGLE" << endl;
            outfile << "Left angle's coordinates are (" << ptrTemp->shp.xLeftUpCorner << ", "
            << ptrTemp->shp.yLeftUpCorner << ')' << endl;
            outfile << "Right angle's coordinates are (" << ptrTemp->shp.xRightDownCorner << ", "
                    << ptrTemp->shp.yRightDownCorner << ')' << endl;
        }
        switch(ptrTemp->shp.color) {
            case 0:
                color = "red";
            break;
            case 1:
                color = "orange";
            break;
            case 2:
                color = "yellow";
            break;
            case 3:
                color = "green";
            break;
            case 4:
                color = "blue";
            break;
            case 5:
                color = "cyan";
            break;
            case 6:
                color = "purple";
            break;
        }
        outfile << "Color is " << color << endl << endl;
        ptrTemp = ptrTemp->next;
        figuresCount++;
    } while (ptrTemp != ptrHead);
    outfile << "Number of shapes is " << figuresCount;
    return true;
}