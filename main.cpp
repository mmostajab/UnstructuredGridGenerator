// STD
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// GLM
#include <glm/glm.hpp>

#include "AABB.h"

std::vector<AABB>           cellBoxes;
std::vector<glm::vec3>      cellVectors;
std::vector<glm::vec3>      points;
std::vector<glm::vec3>      m_pointVectors;
std::vector<glm::u32>       cellPoints;
std::vector<glm::u32>       cellPointsBegIndices;
std::vector<glm::u32>       cellNeighbours;
std::vector<glm::u32>       cellNeighboursBegIndices;
std::vector<glm::u32>       outterSurfaceIndices;
std::vector<glm::float32>   cellVolumes;

bool saveBinary(std::string filename)
{
  std::ofstream out(filename.c_str(), std::ios_base::binary);

  if (out)
  {
    std::cout << "saveBinary: saving " << filename << std::endl;

    size_t cellBoxesNumber = cellBoxes.size();
    size_t pointsNumber = points.size();
    size_t cellPointsNumber = cellPoints.size();
    size_t cellPointsBegIndicesNumber = cellPointsBegIndices.size();
    size_t cellNeighboursNumber = cellNeighbours.size();
    size_t cellNeighboursBegIndicesNumber = cellNeighboursBegIndices.size();
    size_t cellVectorsNumber = cellVectors.size();
    size_t pointVectorsNumber = m_pointVectors.size();
    size_t cellVolumesNumber = cellVolumes.size();
    size_t outterSurfaceTrianglesNumber = outterSurfaceIndices.size();


    out << cellBoxesNumber << std::endl;
    out << pointsNumber << std::endl;
    out << cellVectorsNumber << std::endl;
    out << cellPointsNumber << std::endl;
    out << cellPointsBegIndicesNumber << std::endl;
    out << cellNeighboursNumber << std::endl;
    out << cellNeighboursBegIndicesNumber << std::endl;
    out << pointVectorsNumber << std::endl;
    out << cellVolumesNumber << std::endl;
    out << outterSurfaceTrianglesNumber << std::endl;


    out.write((char*)(&cellBoxes[0]), sizeof(AABB)*cellBoxesNumber);
    out.write((char*)(&points[0]), sizeof(glm::vec3)*pointsNumber);
    out.write((char*)(&cellVectors[0]), sizeof(glm::vec3)*cellVectorsNumber);
    out.write((char*)(&cellPoints[0]), sizeof(glm::u32)*cellPointsNumber);
    out.write((char*)(&cellPointsBegIndices[0]), sizeof(glm::u32)*cellPointsBegIndicesNumber);
    out.write((char*)(&cellNeighbours[0]), sizeof(glm::u32)*cellNeighboursNumber);
    out.write((char*)(&cellNeighboursBegIndices[0]), sizeof(glm::u32)*cellNeighboursBegIndicesNumber);
    out.write((char*)(&m_pointVectors[0]), sizeof(glm::vec3)*pointVectorsNumber);
    out.write((char*)(&cellVolumes[0]), sizeof(glm::float32)*cellVolumesNumber);
    out.write((char*)(&outterSurfaceIndices[0]), sizeof(glm::u32)*outterSurfaceTrianglesNumber);
  }

  return !!out;
}

glm::vec3 deriv_function(const glm::vec3& p)
{
  glm::vec3 ret_val(1.0f, 1.0f, 1.0f);

  return ret_val;
}

int main() {

  size_t dims[3] = { 200, 200, 200 };
  AABB   scene_bounds;

  scene_bounds.min = glm::vec3(-2);
  scene_bounds.max = glm::vec3(+2);

  glm::vec3 len = scene_bounds.max - scene_bounds.min;
  glm::vec3 elem_dim(len.x / dims[0], len.y / dims[1], len.z / dims[2]);

  // Setting the points velocities.
  for (size_t k = 0; k <= dims[2]; k++){
    for (size_t j = 0; j <= dims[1]; j++){
      for (size_t i = 0; i <= dims[0]; i++){

        glm::vec3 p(static_cast<float>(i) / dims[0] * len[0], static_cast<float>(j) / dims[1] * len[1], static_cast<float>(k) / dims[2] * len[2]);
        p += scene_bounds.min;

        std::cout << p.x << " " << p.y << " " << p.z << std::endl;

      }
    }
  }
  
}
