#include "TextQuery.h"
#include "QueryResult.h"
#include "Query.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "WordQuery.h"
#include "NotQuery.h"
#include <iostream>

int main()
{
    std::ifstream file("../data/storyDataFile.txt");
    if(!file)
    {
        return -1;
    }
    TextQuery tQuery(file);
    Query q1 = Query("Daddy");
    std::cout << q1.eval(tQuery);
    Query q2 = ~Query("Alice");
    std::cout << q2.eval(tQuery);
    Query q3 = Query("hair") | Query("Alice");
    std::cout << q3.eval(tQuery);
    Query q4 = Query("hair") & Query("Alice");
    std::cout << q4.eval(tQuery);

    return 0;
}