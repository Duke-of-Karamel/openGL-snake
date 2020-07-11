#include <vector>


namespace Shape
{
    class Shape
    {
        public:

        virtual std::vector<float> getVerticies();
        virtual std::vector<int> getIndexing();
    };

    class Square : virtual Shape
    {
        std::vector<float> getVerticies()
        {
            std::vector<float> positions   {0.5, 0.5,
                                            0.5, 0.5,
                                            0.5, 0.5,
                                            0.5, 0.5}; // 4 verticies * 2 dimensions

            return positions;
        }

        std::vector<int> getIndexing()
        {
            std::vector<int> positions {1,2,3,2,3,4};

            return positions;
        }
    };

    class Circle : virtual Shape
    {
        std::vector<float> getVerticies()
        {
            std::vector<float> positions {}; //TODO: 

            return positions;
        }

        std::vector<int> getIndexing()
        {
            std::vector<int> positions {}; //TODO: 

            return positions;
        }
    };

}