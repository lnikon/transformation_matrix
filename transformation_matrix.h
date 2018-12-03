#ifndef TRANSFORMATION_MATRIX
#define TRANSFORMATION_MATRIX

/* m11 m12 m13 */
// m21 m22 m23
// m31 m32 m33
//
// x' = m11*x + m21*y + dx
// y' = m22*y + m12*x + dy
// if (is not affine) {
//     w' = m13*x + m23*y + m33
//     x' /= w'
//     y' /= w'
// }
/*  */

#include <vector>
#include <utility>

class TransformationMatrix
{
    public:
        typedef std::vector<std::vector<int>>  Matrix3x3;
        enum TransformationType { 
            NoTransformation = 1,
            Translate,
            Rotate,
            Scale,
            Project,
            Shear 
        };

        TransformationMatrix();

        explicit TransformationMatrix(Matrix3x3 fromMatrix);

        TransformationMatrix(int m11, int m12, int m13,
                             int m21, int m22, int m23,
                             int m31, int m32, int m33);

        virtual ~TransformationMatrix();

        int m11() const;
        int m12() const;
        int m13() const;
        int m21() const;
        int m22() const;
        int m23() const;
        int m31() const;
        int m32() const;
        int m33() const;
        int dx() const;
        int dy() const;

    private:
        const std::size_t m_trMatrixWidth = 3;
        const std::size_t m_trMatrixHeight = 3;

        Matrix3x3 m_trMatrix;

        int m_dx;
        int m_dy;

        void setupTransformationMatrix();
        void setupTransformationMatrix(int m11, int m12, int m13,
                                       int m21, int m22, int m23,
                                       int m31, int m32, int m33);
};
#endif
