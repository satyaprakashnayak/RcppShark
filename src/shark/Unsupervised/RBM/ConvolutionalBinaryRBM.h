/*!
 * 
 *
 * \brief       Typedefs for the Binary-Binary RBM.
 *
 * \author      Oswin Krause Asja Fischer
 * \date        1.2014
 *
 *
 * \par Copyright 1995-2015 Shark Development Team
 * 
 * <BR><HR>
 * This file is part of Shark.
 * <http://image.diku.dk/shark/>
 * 
 * Shark is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published 
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Shark is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with Shark.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef SHARK_UNSUPERVISED_RBM_BINARYCONVOLUTIONALRBM_H
#define SHARK_UNSUPERVISED_RBM_BINARYCONVOLUTIONALRBM_H

#include <shark/Unsupervised/RBM/ConvolutionalRBM.h>

#include <shark/Unsupervised/RBM/Neuronlayers/BinaryLayer.h>
#include <shark/Unsupervised/RBM/Sampling/GibbsOperator.h>
#include <shark/Unsupervised/RBM/Sampling/TemperedMarkovChain.h>
#include <shark/Unsupervised/RBM/Sampling/MarkovChain.h>

#include <shark/Unsupervised/RBM/GradientApproximations/ContrastiveDivergence.h>
#include <shark/Unsupervised/RBM/GradientApproximations/MultiChainApproximator.h>
#include <shark/Unsupervised/RBM/GradientApproximations/SingleChainApproximator.h>
#include <shark/Rng/GlobalRng.h>
namespace shark{

typedef ConvolutionalRBM<BinaryLayer,BinaryLayer, Rng::rng_type> ConvolutionalBinaryRBM;
typedef GibbsOperator<ConvolutionalBinaryRBM> ConvolutionalBinaryGibbsOperator;
typedef MarkovChain<ConvolutionalBinaryGibbsOperator> ConvolutionalBinaryGibbsChain;
typedef TemperedMarkovChain<ConvolutionalBinaryGibbsOperator> ConvolutionalBinaryPTChain;

typedef MultiChainApproximator<ConvolutionalBinaryGibbsChain> ConvolutionalBinaryPCD;
typedef ContrastiveDivergence<ConvolutionalBinaryGibbsOperator> ConvolutionalBinaryCD;
typedef SingleChainApproximator<ConvolutionalBinaryPTChain> ConvolutionalBinaryParallelTempering;
}

#endif

