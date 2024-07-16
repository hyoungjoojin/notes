# Vertex Shader

- The vertex shader processes every vertex positioned in the model space and transforms it to clip space.

## MVP (Model View Projection)
- The vertex position is transformed by three matrices; model, view, and projection.
```math
v' = P * V * M * v
```

## View
- The world space is the coordinate system where all objects exist.
- The camera space is the coordinate system viewed from the camera, where the origin is at the camera and the -Z axis is where the camera is viewing.
- The camera has a model matrix that defines its position in the world space.
- The inverse of the camera's model matrix is the view matrix. This view matrix transforms vertices to the camera space from the world space.

## Projection
- Vertices in the camera space are transformed to clip space by projection.
- Projection Types
    - Perspective
    - Orthographic
- Clip space coordinates are 4-dimensional homogeneous vectors. Applying perspective division (making them 3-dimensional by dividing each value by the 4th dimension value) makes the vector in NDC (normalized device coordinates).

