#include "transformation_matrix.h"

TransformationMatrix::TransformationMatrix()
    : m_dx(0), m_dy(0) { 
    
    setupTransformationMatrix();
}

TransformationMatrix::TransformationMatrix(Matrix3x3 fromMatrix) 
    : m_trMatrix(fromMatrix), 
    m_dx(0), m_dy(0), 
    m_type(NoTransformation), m_dirty(NoTransformation) {
}

TransformationMatrix::TransformationMatrix(int m11, int m12, int m13,
                                           int m21, int m22, int m23,
                                           int m31, int m32, int m33)
   : m_dx(0), m_dy(0),
    m_type(NoTransformation), m_dirty(Project) {

    setupTransformationMatrix(m11, m12, m13,
                              m21, m22, m23,
                              m31, m32, m33);
}

TransformationMatrix::~TransformationMatrix() { }

int TransformationMatrix::m11() const {
    return m_trMatrix[0][0];
}

int TransformationMatrix::m12() const {
    return m_trMatrix[0][1];
}

int TransformationMatrix::m13() const { 
    return m_trMatrix[0][2];
}

int TransformationMatrix::m21() const { 
    return m_trMatrix[1][0];
}

int TransformationMatrix::m22() const { 
    return m_trMatrix[1][1];
}

int TransformationMatrix::m23() const { 
    return m_trMatrix[1][2];
}

int TransformationMatrix::m31() const { 
    return m_trMatrix[2][0];
}

int TransformationMatrix::m32() const { 
    return m_trMatrix[2][1];
}

int TransformationMatrix::m33() const { 
    return m_trMatrix[2][2];
}

int TransformationMatrix::dx() const {
    return m_dx;
}

int TransformationMatrix::dy() const {
    return m_dy;
}


TransformationMatrix::TransformationType TransformationMatrix::trType()
{
    if(m_dirty > m_type)
    {
        return static_cast<TransformationType>(m_dirty);
    }


}

void TransformationMatrix::setupTransformationMatrix() {
    m_trMatrix.resize(m_trMatrixHeight);
    for(std::size_t i = 0; i < m_trMatrixHeight; i++)
    {
        m_trMatrix[i].resize(m_trMatrixHeight);
    }
}

void TransformationMatrix::setupTransformationMatrix(int m11, int m12, int m13,
                                                     int m21, int m22, int m23,
                                                     int m31, int m32, int m33) {
    setupTransformationMatrix();

    m_trMatrix[0][0] = m11;
    m_trMatrix[0][1] = m12;
    m_trMatrix[0][2] = m13;

    m_trMatrix[1][0] = m21;
    m_trMatrix[1][1] = m22;
    m_trMatrix[1][2] = m23;

    m_trMatrix[2][0] = m31;
    m_trMatrix[2][1] = m32;
    m_trMatrix[2][2] = m33;
}
