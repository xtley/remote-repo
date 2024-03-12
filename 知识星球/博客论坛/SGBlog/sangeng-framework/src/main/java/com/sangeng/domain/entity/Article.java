package com.sangeng.domain.entity;

import java.util.Date;
import java.io.Serializable;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * (Article)表实体类
 *
 * @author makejava
 * @since 2024-01-03 22:24:02
 */
@SuppressWarnings("serial")
@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("sg_article")
public class Article {
    @TableId
    private Long id;
//标题
    private String title;
//文章内容
    private String content;
//文章类型：1 文章 2 草稿
    private String type;
//文章摘要
    private String summary;
//所属分类:id
    private Long categoryId;
//缩略图
    private String thumbnail;
//是否置顶（0否，1是）
    private String isTop;
//状态（0已分布。1草稿）
    private String status;
//评论数
    private Integer commentCount;
//访问量
    private Long viewCount;
//是否允许评论 1是 0 否
    private String isComment;

    private String createBy;

    private Date createTime;

    private Long updateBy;

    private Date updateTime;
//删除标志（0代表未删除，1已删除）
    private Integer delFlag;




}

