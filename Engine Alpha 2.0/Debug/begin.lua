
VERTEX_SHADER = 0
TESS_CONTROL_SHADER = 1
TESS_EVALUATION_SHADER = 2
GEOMETRY_SHADER = 3
COMPUTE_SHADER = 4
FRAGMENT_SHADER = 5




vert_shader = createShader("Vertex 1", VERTEX_SHADER, "cube.vert")
frag_shader = createShader("Frag 1", FRAGMENT_SHADER, "cube.frag")

program = createProgram("Demo Program 1")

addShaderToProgram(program, VERTEX_SHADER, vert_shader)
addShaderToProgram(program, FRAGMENT_SHADER, frag_shader)

linkProgram(program, 0)

cube_vertex, cube_index = setDemoGraphicInterface()

cube_drawing = createCubeDrawing("Cube Drawing", cube_index)

setProgramToDrawing(cube_drawing, program)

matchBufferToDrawing(cube_drawing, cube_vertex)




world_1 = createWorld("world 1")
setCurrentWorld(world_1)

camera = {}
camera.position = {0.0, 0.0, -10.0}
camera.up = {0.0, 1.0, 0.0}
camera.lookat = {0.0, 0.0, 0.0}

createCameraToWorld(world_1, camera)

setDemoWorldInterface(cube_drawing)
