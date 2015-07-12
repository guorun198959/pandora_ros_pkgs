/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2015, P.A.N.D.O.R.A. Team.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the P.A.N.D.O.R.A. Team nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors:
 *   Tsirigotis Christos <tsirif@gmail.com>
 *********************************************************************/

#include <string>
#include <vector>

#include <pluginlib/class_list_macros.h>
#include <opencv2/opencv.hpp>

#include "sensor_processor/handler.h"
#include "sensor_processor/abstract_processor.h"
#include "pandora_vision_msgs/EnhancedImage.h"
#include "pandora_vision_msgs/RegionOfInterest.h"

#include "frame_matcher/points_on_frame.h"
#include "frame_matcher/enhanced_image_postprocessor.h"

PLUGINLIB_EXPORT_CLASS(pandora_data_fusion::frame_matcher::EnhancedImagePostProcessor,
    sensor_processor::AbstractProcessor)

namespace pandora_data_fusion
{
namespace frame_matcher
{

  /**
   * @details TODO
   */
  EnhancedImagePostProcessor::
  EnhancedImagePostProcessor() {}

  /**
   * @details TODO
   */
  bool
  EnhancedImagePostProcessor::
  postProcess(const PointsOnFrameConstPtr& input, const pandora_vision_msgs::EnhancedImagePtr& output)
  {
    ROS_INFO("[%s] post process", this->getName().c_str());
    output->header = input->header;

    output->rgbImage = input->rgbImage;
    output->isDepth = false;

    for (int ii = 0; ii < input->pointsVector.size(); ++ii) {
      pandora_vision_msgs::RegionOfInterest roi;
      std::vector<cv::Point2f> points = input->pointsVector.at(ii);

      roi.width = points[2].x - points[0].x;
      roi.height = points[2].y - points[0].y;
      roi.center.x = (points[2].x + points[0].x) / 2;
      roi.center.y = (points[2].y + points[0].y) / 2;

      output->regionsOfInterest.push_back(roi);
    }

    return true;
  }

}  // namespace frame_matcher
}  // namespace pandora_data_fusion
