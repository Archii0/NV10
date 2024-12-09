// IGPU.h
#ifndef IGPU_H
#define IGPU_H

#include <vector>

// Forward declarations of types (replace with actual definitions)
struct Command;
struct Vertex;
struct Texture;
struct Framebuffer;

class IAccelerator {
   public:
    virtual void initialize() = 0;
    virtual void executeCommand(const Command& cmd) = 0;
    virtual void loadVertexData(const std::vector<Vertex>& vertices) = 0;
    virtual void loadTexture(const Texture& texture) = 0;
    virtual Framebuffer render() = 0;
    virtual ~IAccelerator() = default;
};

#endif  // IGPU_H