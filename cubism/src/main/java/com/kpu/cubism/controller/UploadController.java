package com.kpu.cubism.controller;

import java.io.Writer;
import java.util.List;
import java.util.Map;
import java.util.Set;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import com.kpu.cubism.service.UploadService;
import com.kpu.cubism.vo.UploadVo;



@Controller
public class UploadController {
	private static final Logger logger = LoggerFactory.getLogger(UploadController.class);
	
	
	@Autowired
	private UploadService service;
	
		// 업로드 action
		@RequestMapping("/upload")
		public String getBbsInsert(RedirectAttributes rttr, ModelMap modelMap, Map<String,Object> map,
				@ModelAttribute UploadVo uploadVO, RedirectAttributes redirectAttributes, HttpServletRequest request, HttpServletResponse response, Writer out) throws Exception{

			//System.out.println("uploadController Start =================================================");
			Set path = request.getSession().getServletContext().getResourcePaths("/");
			System.out.println("Path : " + path);
			try{
				boolean result;
				result = service.getUploadInsert(uploadVO, map, request);
				System.out.println("Upload Success");
				
				if(result != false){ // 파일 저장 성공
					redirectAttributes.addFlashAttribute("msg","regsuccess");
			    } 

					return "redirect:/uploadList";

			}catch (Exception e) {
	            if (logger.isErrorEnabled()) {
	                logger.error(e.getMessage(), e);
	            }
	        }

			return null;
		}
		
		@RequestMapping(value = "/uploadList", method = RequestMethod.GET)
		public String getList(ModelMap modelMap, @ModelAttribute UploadVo vo) {

			List<UploadVo> uploadList = service.getUploadList(vo);
			System.out.println("list size : " + uploadList.size());
			modelMap.addAttribute("list", uploadList);
			
			return "/upload/myuploadlist";
			
		}
		@RequestMapping(value = "/GGuploadList", method = RequestMethod.GET)
		public String getListGG(ModelMap modelMap, @ModelAttribute UploadVo vo) {

			List<UploadVo> uploadList = service.getGGUploadList(vo);
			System.out.println("list size : " + uploadList.size());
			modelMap.addAttribute("list", uploadList);
			
			return "/upload/myGGuploadlist";
			
		}
}     