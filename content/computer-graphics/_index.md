+++
title = "computer-graphics"
+++

# Computer Graphics

## Rasterization

Rasterization is the process of rendering images by deciding which pixels to light up
given a geometric primitive for all input primitives. Rasterization is fast, but hard
to achieve photorealistic imagery.

The geometric primitives are represented as triangles because triangles can approximate
any shape, is always planar, and is easy to interpolate data at the vertices.

The rasterization pipeline is as follows.

- Transform and position objects in the world.
- Project the objects onto a screen.
- Determine which pixels are covered by the triangle.
- Interpolate triangle attributes over the computed pixels.
- Sample texture maps and evaluate shaders.
- Combine samples into one final image.

Determining which pixels are covered by a triangle is a problem of coverage and occlusion.
Coverage is determining if a pixel is covered by a triangle or not, and occlusion is determining
if a triangle is the first thing the pixel sees.

To compute coverage, we could compute the exact fraction of pixel area that is covered by
a triangle. However, this is unnecessarily complex and impractical. Instead, we view the
coverage problem as a sampling problem. Here, a set of points are sampled from each pixel
which are then used to determine the coverage for the entire pixel. Edge cases where the
sampled is placed directly on top of an edge needs to considered. OpenGL and Direct3D
classifies the sample as covered if the edge is a top edge or a left edge.

Sampling is the process of turning a continuous signal into a discrete signal by taking values
over a discrete set of points. Reconstruction is the process of generating a continous signal
from a discrete set of samples.

Aliasing is a side-effect of sampling/reconstruction, where high frequencies in the original
signal becomes a different lower frequency value due to undersampling. Aliasing effects include
jagged lines, shimmering effects on images, and Moiré patterns.
If the frequency is bounded we can use the Nyquist-Shannon theorem to remove aliasing, which
states that a continuous signal can be perfectly reconstructed from samples if the sampling
rate is at least twice the highest frequency component in the signal.

For anti-aliasing sampled pixels, we can sample more points within a pixel. This is called
super-sampling. For example, we could sample 4 points on a pixel and use the number of covered
pixels to approximate the fraction of the pixel area covered.

Determining if a point is covered by a triangle can be done using linear algebra.
There are multiple ways to decide which points should be computed and in which order should they
be computed.

- Incremental Traversal: Visit pixels incrementally starting from some point. The order in which
  the pixels are visited can be optimized for memory coherence using methods like Hilbert curves
  or Morton curves.
- Parallel Computation: Using GPUs, we can compute the coverage for every single point.
- Tiled Triangle Traversal: We can use a tiled approach, where if a certain area of pixels do not
  cover a triangle at all or if the area is entirely covered by a triangle we can early return
  and don't compute the individual pixel values within the tile.
- Hierarchial Strategy: We can recursively use the tiled triangle traversal approach.

## Ray Tracing

Ray tracing is the process of rendering images by deciding which primitives can be seen
given a pixel for all pixels.
