echo "g++ -std=c++17 -o beta src/Node.cc src/Greedy.cc src/Dynamic.cc src/Strong.cc src/TSP.cc main.cc"
g++ -std=c++17 -o beta src/Node.cc src/Greedy.cc src/Dynamic.cc src/Strong.cc src/TSP.cc main.cc
echo "./beta ./files/ 30000"
./beta ./files/ 30000