#shader vertex
#version 330 core
        
layout (location = 0) in vec4 position;
layout (location = 1) in vec2 textureCoordinate;

// Output vertex shader data (texture coordinate) to fragment shader
out vec2 v_TextureCoordinate;

uniform mat4 u_Camera;
        
void main()
{
    gl_Position = position * u_Camera;
    v_TextureCoordinate = textureCoordinate;
};

#shader fragment
#version 330 core
        
layout (location = 0) out vec4 color;

// Gets texture coordinate as input
in vec2 v_TextureCoordinate;
        
uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
    vec4 textureColor = texture(u_Texture, v_TextureCoordinate);
    color = textureColor;
};