# Computer Graphics

> 3

What is rasterization?

--

Rasterization is the process of transforming geometric primitives into a raster
image (a grid of pixels).

--

> 3

Why do problems like jagged lines happen during rasterization and how can we fix them?

--

Those problems are aliasing problems. It happens because the high frequency values of the
pixels (values being in a continuous range) becomes limited to a lower frequency range (0 or 1).
This can be partly solved by sampling the pixel values in a higher frequency, which can be done by
sampling multiple points from each pixel (super-sampling).

--
