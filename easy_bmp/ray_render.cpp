
//You'll have to adjust this to work with your implementation of homeworks 2 through 4.
void RenderRays(){
    BMP output;
    output.SetSize(camera.width, camera.height);
    output.SetBitDepth(24);

    for(int x = 0; x < camera.width; x++){
        for(int y = 0; y < camera.height; y++){

            Ray r = Raycast(x, y);
            vec4 rgb = abs(r.direction) * 255;//r.direction is, of course, a vec4.
                                              //You'll have to write an absolute value
                                              //function that takes a vec4 as its argument.

            output(x, y)->Red = rgb[0];
            output(x, y)->Green = rgb[1];
            output(x, y)->Blue = rgb[2];
        }
    }
    output.WriteToFile("rays.bmp");
}