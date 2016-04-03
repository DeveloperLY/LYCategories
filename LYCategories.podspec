Pod::Spec.new do |s|
s.name         = 'LYCategories'
s.summary      = 'A set of useful categories for Foundation and UIKit.'
s.version      = '0.8.9'
s.license      = { :type => 'MIT', :file => 'LICENSE' }
s.authors      = { 'CoderYLiu' => 'coderyliu@gmail.com' }
s.social_media_url = 'http://www.jianshu.com/users/455a0339b2c3/latest_articles'
s.homepage     = 'https://github.com/CoderYLiu/LYCategories'
s.platform     = :ios, '6.0'
s.ios.deployment_target = '6.0'
s.source       = { :git => 'https://github.com/CoderYLiu/LYCategories.git', :tag => s.version.to_s }

s.requires_arc = true
s.source_files = 'LYCategories/**/*.{h,m}'
s.public_header_files = 'LYCategories/**/*.{h}'

non_arc_files = 'LYCategories/GTMBase64/GTMBase64.{h,m}', 'LYCategories/GTMBase64/GTMDefines.{h,m}'
s.ios.exclude_files = non_arc_files
s.subspec 'no-arc' do |sna|
sna.requires_arc = false
sna.source_files = non_arc_files
end

s.libraries = 'z'
s.frameworks = 'UIKit', 'CoreFoundation' ,'QuartzCore', 'CoreGraphics', 'CoreImage', 'CoreText', 'ImageIO', 'Accelerate'

end
