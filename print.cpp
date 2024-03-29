#include "class.hpp"
using namespace std;
int _xsize;
int _ysize;
int _x;
int _y;
void mmapPrint(multimap<float, Line *> &ptr)
{
    vector<Line *> tmp;
    for (auto &it : ptr)
    {
        tmp.push_back(it.second);
    }
    print(tmp);
}
void printALL(){
    vector<Line *> tmp;
    Index *cur = v_right;
    while (cur != nullptr)
    {
        if (cur->Lptr != nullptr)
        {
            tmp.push_back(cur->Lptr);
        }
        cur = cur->next;
    }
    cur = v_left;
    while (cur != nullptr)
    {
        if (cur->Lptr != nullptr)
        {
            tmp.push_back(cur->Lptr);
        }
        cur = cur->next;
    }
    cur = h_up;
    while (cur != nullptr)
    {
        if (cur->Lptr != nullptr)
        {
            tmp.push_back(cur->Lptr);
        }
        cur = cur->next;
    }
    cur = h_down;
    while (cur != nullptr)
    {
        if (cur->Lptr != nullptr)
        {
            tmp.push_back(cur->Lptr);
        }
        cur = cur->next;
    }
    print(tmp);
}
vector<Line *> mmaptovec(multimap<float, Line *> &ptr)
{
    vector<Line *> tmp;
    for (auto &it : ptr)
    {
        tmp.push_back(it.second);
    }
    return tmp;
}
void IndexLptrPrint(Index *&ptr)
{
    vector<Line *> tmp;
    Index *cur = ptr;
    while (cur != nullptr)
    {
        if (cur->Lptr != nullptr)
        {
            tmp.push_back(cur->Lptr);
        }
        cur = cur->next;
    }
    print(tmp);
}
void yIndexptrprint(Index *&yptr)
{
    vector<Line *> tmp;
    Index *cur = yptr;
    while (cur != nullptr)
    {
        if (cur->Lptr != nullptr)
        {
            tmp.push_back(cur->Lptr);
        }
        else
        {
            Line *t = new Line(cur->index, cur->index, cur->low, cur->big, 0);
            tmp.push_back(t);
        }
        cur = cur->next;
    }
    print(tmp);
}
void xIndexptrprint(Index *&xptr)
{
    vector<Line *> tmp;
    Index *cur = xptr;
    while (cur != nullptr)
    {
        if (cur->Lptr != nullptr)
        {
            tmp.push_back(cur->Lptr);
        }
        else
        {
            Line *t = new Line(cur->index, cur->index, cur->low, cur->big, 1);
            tmp.push_back(t);
        }
        cur = cur->next;
    }
    print(tmp);
}
void update(int xsize, int ysize, int xstart, int ystart)
{
    _x = xstart;
    _y = ystart;
    _xsize = xsize;
    _ysize = ysize;
}
void print(std::vector<Line *> &line_ptr)
{
    int x = _xsize;
    int y = _ysize;
    int xmin = _x;
    int ymin = _y;
    vector<vector<int>> print(y, vector<int>(x, 0));
    for (int i = 0; i < line_ptr.size(); i++)
    {
        auto lptr = line_ptr[i];
        if (lptr->type == 1) //verti
        {
            float yl, ys;
            ys = lptr->y1;
            yl = lptr->y2;
            for (int k = ys; k <= yl; k++)
            {
                print[k - ymin][lptr->x1 - xmin] = 1;
            }
        }
        else if (lptr->type == 0) //horiz
        {
            for (int j = lptr->x1; j <= lptr->x2; ++j)
            {
                print[lptr->y1 - ymin][j - xmin] = 1;
            }
        }
    }
    cout << endl;

    for (int i = print.size() - 1; i >= 0; --i)
    {
        cout << "row = " << i + ymin << "  \t";
        for (int j = 0; j < print[i].size(); j++)
        {
            print[i][j] ? (cout << "+") : (cout << " ");
        }
        cout << endl;
    }
    cout << "row = x"
         << "  \t";
    for (int i = xmin; i < xmin + x; i++)
    {
        cout << abs(i % 10);
    }
    cout << "\n"
         << endl;
}
void print(std::vector<Line *> &line_ptr, int x, int y, int xmin, int ymin)
{
    vector<vector<int>> print(y, vector<int>(x, 0));
    for (int i = 0; i < line_ptr.size(); i++)
    {
        auto lptr = line_ptr[i];
        /*if (print[28][56] == 1)
        {
            cout << "fuck";
        }
        */
        if (lptr->type == 1) //verti
        {
            float yl, ys;
            //lptr->y1 > lptr->y2 ? (yl = lptr->y1, ys = lptr->y2) : (yl = lptr->y2, ys = lptr->y1);
            ys = lptr->y1;
            yl = lptr->y2;
            for (int k = ys; k <= yl; k++)
            {
                print[k - ymin][lptr->x1 - xmin] = 1;
            }
        }
        else if (lptr->type == 0) //horiz
        {
            /*if (lptr->x1 <= lptr->x2)
            {
                for (int j = lptr->x1 - xmin; j <= lptr->x2 - xmin; j++)
                {
                    print[lptr->y1 - ymin][j] = 1;
                }
            }
            else if (lptr->x1 > lptr->x2)
            {
                for (int j = lptr->x2 - xmin; j <= lptr->x1 - xmin; j++)
                {
                    print[lptr->y1 - ymin][j] = 1;
                }
            }*/
            for (int j = lptr->x1; j <= lptr->x2; ++j)
            {
                print[lptr->y1 - ymin][j - xmin] = 1;
            }
        }
        /*else if (lptr->type == 2) //slash
        {
            const auto it = line_ptr[i];
            //get m
            if ((int)((it->x1 - it->x2) / (it->y1 - it->y2)) == 1)
            {
                if (it->x1 < it->x2)
                {
                    for (int k = it->x1 - xmin; k <= it->x2 - xmin; k++)
                    {
                        print[it->y1 - ymin + (k - (it->x1 - xmin))][k] = 1;
                    }
                }
                else if (it->x2 < it->x1)
                {
                    for (int k = it->x2 - xmin; k <= it->x1 - xmin; k++)
                    {
                        print[it->y2 - ymin + (k - (it->x2 - xmin))][k] = 1;
                    }
                }
            }
            else if ((int)((it->x1 - it->x2) / (it->y1 - it->y2)) == -1)
            {
                if (it->x1 < it->x2)
                {
                    for (int k = it->x1 - xmin; k <= it->x2 - xmin; k++)
                    {
                        print[it->y1 - ymin - (k - (it->x1 - xmin))][k] = 1;
                    }
                }
                else if (it->x2 < it->x1)
                {
                    for (int k = it->x2 - xmin; k <= it->x1 - xmin; k++)
                    {
                        print[it->y2 - ymin - (k - (it->x2 - xmin))][k] = 1;
                    }
                }
            }
        }*/
    }
    cout << "\n";

    for (int i = print.size() - 1; i >= 0; --i)
    {
        cout << "row = " << i + ymin << "  \t";
        for (int j = 0; j < print[i].size(); j++)
        {
            print[i][j] ? (cout << "+") : (cout << " ");
        }
        cout << "\n";
    }
    cout << "row = x"
         << "  \t";
    for (int i = xmin; i < xmin + x; i++)
    {
        cout << abs(i % 10);
    }
    cout << "\n\n";
}
/*vector<Line*> combine(vector<Line*>&a,vector<Line*>&b){
    vector<Line*> tmp;
    tmp.reserve(a.size() + b.size()); // preallocate memory
    tmp.insert(tmp.end(), a.begin(), a.end());
    tmp.insert(tmp.end(), b.begin(), b.end());
    return tmp;
}
vector<Line*> combine(vector<Line*>&a,multimap<float,Line*>&_b){
    vector<Line*> b = mmaptovec(_b);
    vector<Line*> tmp;
    tmp.reserve(a.size() + b.size()); // preallocate memory
    tmp.insert(tmp.end(), a.begin(), a.end());
    tmp.insert(tmp.end(), b.begin(), b.end());
    
    return tmp;
}
*/
void combine(vector<Line *> &a, multimap<float, Line *> &_b)
{
    vector<Line *> b = mmaptovec(_b);
    a.reserve(a.size() + b.size()); // preallocate memory
    //tmp.insert(tmp.end(), a.begin(), a.end());
    a.insert(a.end(), b.begin(), b.end());
}
