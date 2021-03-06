#pragma once

#include <gtsam/geometry/Pose3.h>
#include <gtsam/slam/BetweenFactor.h>
#include <gtsam/nonlinear/Symbol.h>
#include <omnimapper/pose_plugin.h>
#include <omnimapper/omnimapper_base.h>

namespace omnimapper
{
  // Forward Declaration
  class OmniMapperBase;

  /** \brief PosePlugin is used to add constraints between consecutive poses in a SLAM problem. */
  class NoMotionPosePlugin : public omnimapper::PosePlugin
  {
    protected:
      /** \brief A reference to the mapper we're a plugin for. */
      OmniMapperBase* mapper_;
      bool initialized_;
      
    public:
      NoMotionPosePlugin (omnimapper::OmniMapperBase* mapper);

      gtsam::BetweenFactor<gtsam::Pose3>::shared_ptr addRelativePose (boost::posix_time::ptime t1, gtsam::Symbol sym1, boost::posix_time::ptime t2, gtsam::Symbol sym2);
      bool ready ();
  };
}
