#version 330

uniform int type;   // 0 = Normal, 1 = Protanopia, 2 = Deuteranopia, 3 = Tritanopia

in vec2 fragTexCoord;
in vec4 fragColor;

uniform sampler2D texture0;

out vec4 finalColor;

void main()
{
    vec4 color = texture(texture0, fragTexCoord);

    if (type == 1) { 
        // Protanopia simulation
        float r = color.r * 0.567 + color.g * 0.433;
        float g = color.r * 0.558 + color.g * 0.442;
        float b = color.b;
        finalColor = vec4(r, g, b, color.a);
    }
    else if (type == 2) { 
        // Deuteranopia simulation
        float r = color.r * 0.625 + color.g * 0.375;
        float g = color.r * 0.7 + color.g * 0.3;
        float b = color.b;
        finalColor = vec4(r, g, b, color.a);
    }
    else if (type == 3) { 
        // Tritanopia simulation
        float r = color.r;
        float g = color.g * 0.95 + color.b * 0.05;
        float b = color.g * 0.433 + color.b * 0.567;
        finalColor = vec4(r, g, b, color.a);
    }
    else {
        // Normal vision (no filter)
        finalColor = color;
    }
}
