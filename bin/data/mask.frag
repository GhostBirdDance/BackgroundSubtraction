uniform sampler2DRect mask;
uniform sampler2DRect tex0;

void main() {
    vec2 texCoord = gl_TexCoord[0].st;
    gl_FragColor = vec4(texture2DRect(mask, texCoord).xyz*texture2DRect(tex0, texCoord).xyz, 1.0);
}