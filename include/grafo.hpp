//Clase que almacena un grafo

#include<vector>
#include<utility>


class grafo{

   private:

      std::vector<std::vector<std::pair<unsigned int, double> > > matriz;

   public:

     grafo(void);

     ~grafo();


};
