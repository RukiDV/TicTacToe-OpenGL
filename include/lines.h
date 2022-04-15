#include "drawable.h"

class Lines : public Drawable {
public:
    Lines(std::vector<Vertex> vertices, std::vector<uint32_t> indices, const std::string& vertexShader, const std::string& fragmentShader, float lineWidth) : 
        Drawable(vertices, indices, vertexShader, fragmentShader), lineWidth(lineWidth) {}

void draw();

private:
    float lineWidth;
};